#ifndef AUDIOPLAYER_LINUX_H
#define AUDIOPLAYER_LINUX_H

#include "audioplayer.h"

#include <alsa/asoundlib.h>
#include <linux/soundcard.h>

#include <atomic>
#include <thread>
#include <vector>

#include "../coreutils/file.h"
#include "../coreutils/log.h"

class InternalPlayer
{
public:
    InternalPlayer(int hz = 44100)
        : hz(hz), quit(false), playback_handle(nullptr), paused(false)
    {
        playerThread = std::thread{&InternalPlayer::run, this};
    };

    void play(std::function<void(int16_t*, int)> cb) { callback = cb; }

    void pause(bool on) { paused = on; }

    ~InternalPlayer()
    {
        quit = true;
        paused = false;
        if (playerThread.joinable())
            playerThread.join();
        if (playback_handle)
            snd_pcm_close(playback_handle);
        snd_config_update_free_global();
    }

    void run()
    {
        int err;
        if ((err = snd_pcm_open(&playback_handle, "default",
                                SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
            fprintf(stderr, "cannot open audio device (%s)\n",
                    snd_strerror(err));
            exit(1);
        }
        if ((err = snd_pcm_set_params(playback_handle, SND_PCM_FORMAT_S16,
                                      SND_PCM_ACCESS_RW_INTERLEAVED, 2, hz, 1,
                                      30000)) < 0) {
            fprintf(stderr, "Playback open error: %s\n", snd_strerror(err));
            exit(1);
        }

        std::vector<int16_t> buffer(8192);
        while (!quit) {
            if (paused)
                utils::sleepms(10);
            else {
                if(callback)
                    callback(&buffer[0], buffer.size());
                else {
                    memset(&buffer[0], 0, buffer.size() * 2);
                }
                writeAudio(&buffer[0], buffer.size());
            }
        }
        if (playback_handle)
            snd_pcm_close(playback_handle);
        playback_handle = nullptr;
    }

    void set_volume(int volume)
    {
        long min, max;
        snd_mixer_t* handle;
        snd_mixer_selem_id_t* sid;
        const char* card = "default";

        // Mixer volume control is best-effort. On setups where the "default"
        // control is a PulseAudio/PipeWire bridge (e.g. WSL) the mixer may be
        // absent or shaped differently, so failures must NOT abort playback.
        if (snd_mixer_open(&handle, 0) < 0) { LOGD("mixer_open failed"); return; }
        if (snd_mixer_attach(handle, card) < 0) {
            LOGD("mixer attach failed"); snd_mixer_close(handle); return;
        }
        if (snd_mixer_selem_register(handle, NULL, NULL) < 0) {
            LOGD("selem register failed"); snd_mixer_close(handle); return;
        }
        if (snd_mixer_load(handle) < 0) {
            LOGD("mixer load failed"); snd_mixer_close(handle); return;
        }

        snd_mixer_selem_id_alloca(&sid);
        snd_mixer_selem_id_set_index(sid, 0);
        snd_mixer_selem_id_set_name(sid, "PCM");
        snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
        if (!elem) {
            // PulseAudio/PipeWire ALSA bridges (and many cards) expose "Master"
            // rather than "PCM"; fall back to it.
            snd_mixer_selem_id_set_name(sid, "Master");
            elem = snd_mixer_find_selem(handle, sid);
        }
        if (elem) {
            // Map 0..100 into the element's ACTUAL raw range. The old code wrote
            // a hardcoded centibel value while ignoring [min,max], which drove
            // bridged mixers (raw range e.g. 0..65536) to ~minimum -> silence.
            snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
            double v = volume * 0.01;
            if (v < 0.0) v = 0.0;
            if (v > 1.0) v = 1.0;
            long val = min + (long)((max - min) * v + 0.5);
            LOGD("VOL>> %d [%ld..%ld] -> %ld", volume, min, max, val);
            snd_mixer_selem_set_playback_volume_all(elem, val);
        } else
            LOGD("Could not change volume (no PCM/Master element)");

        snd_mixer_close(handle);
    }

    void writeAudio(int16_t* samples, int sampleCount)
    {
        int frames =
            snd_pcm_writei(playback_handle, (char*)samples, sampleCount / 2);
        if (frames < 0) {
            snd_pcm_recover(playback_handle, frames, 0);
        }
    }

    int get_delay() const
    {
#ifdef RASPBERRYPI
        return 1;
#else
        return 1;
#endif
    }

    int hz;
    std::function<void(int16_t*, int)> callback;
    std::atomic<bool> quit;
    int dspFD;
    snd_pcm_t* playback_handle;
    std::atomic<bool> paused;
    std::thread playerThread;
};

#endif // AUDIOPLAYER_LINUX_H
