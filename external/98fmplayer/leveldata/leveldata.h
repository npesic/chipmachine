#ifndef MYON_LEVELDATA_H_INCLUDED
#define MYON_LEVELDATA_H_INCLUDED

#ifdef __cplusplus
// GCC/libstdc++ (< 13, and pre-C++23) does not expose the C11 <stdatomic.h>
// names in the global namespace the way clang/libc++ does, so include them
// from <atomic> and bring the ones this header uses into scope. Keeps this C
// header usable from the C++ plugin (FMPPlugin.cpp) on Linux/aarch64.
#include <atomic>
using std::atomic_flag;
using std::memory_order_acquire;
using std::memory_order_release;
using std::memory_order_relaxed;
using std::atomic_flag_test_and_set_explicit;
using std::atomic_flag_clear_explicit;
#else
#include <stdatomic.h>
#endif

struct leveldata {
  atomic_flag flag;
  unsigned level;
  bool read;
};

static inline unsigned leveldata_read(struct leveldata *data) {
  while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
  unsigned level = data->level;
  data->read = true;
  atomic_flag_clear_explicit(&data->flag, memory_order_release);
  return level;
}

static inline void leveldata_update(struct leveldata *data, unsigned level) {
  while (atomic_flag_test_and_set_explicit(&data->flag, memory_order_acquire));
  if (data->read || (level > data->level)) data->level = level;
  data->read = false;
  atomic_flag_clear_explicit(&data->flag, memory_order_release);
}

static inline void leveldata_init(struct leveldata *data) {
#ifdef __cplusplus
  // std::atomic_flag is not copy-assignable, so the C compound-literal reset
  // below is ill-formed in C++; reset the plain fields directly instead.
  data->level = 0;
  data->read = false;
#else
  *data = (struct leveldata) {0};
#endif
  atomic_flag_clear_explicit(&data->flag, memory_order_relaxed);
}

#endif // MYON_LEVELDATA_H_INCLUDED
