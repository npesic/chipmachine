# Testing CM

WSL from command line

## ISSUE 1

No sound output

## ALSA log

```
pactl list sink-inputs
Sink Input #7
        Driver: protocol-native.c
        Owner Module: 21
        Client: 5
        Sink: 1
        Sample Specification: s16le 2ch 44100Hz
        Channel Map: front-left,front-right
        Format: pcm, format.sample_format = "\"s16le\""  format.rate = "44100"  format.channels = "2"  format.channel_map = "\"front-left,front-right\""
        Corked: no
        Mute: no
        Volume: front-left: 65536 / 100% / 0.00 dB,   front-right: 65536 / 100% / 0.00 dB
                balance 0.00
        Buffer Latency: 30000 usec
        Sink Latency: 51719 usec
        Resample method: n/a
        Properties:
                media.name = "ALSA Playback"
                application.name = "ALSA plug-in [cm]"
                native-protocol.peer = "UNIX socket client"
                native-protocol.version = "35"
                application.process.id = "81058"
                application.process.user = "lab"
                application.process.host = "DESKTOP-BUCQL57"
                application.process.binary = "cm"
                application.language = "C"
                window.x11.display = ":0"
                application.process.machine_id = "a10d9f5132fc4b109ae0b1773249f301"
                module-stream-restore.id = "sink-input-by-application-name:ALSA plug-in [cm]"
```
