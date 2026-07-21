# Regression

After merging code for 2.0 version text mode is not working any more

## Issue

* starting with cm -X
* type something to search (search works and file selection works)
* on pressing enter to start playing the music file the app crashes:
```
C:/msys64/mingw64/include/c++/16.1.0/bits/stl_queue.h:262: std::queue<_Tp, _Sequence>::reference std::queue<_Tp, _Sequence>::front() [with _Tp = unsigned char; _Sequence = std::deque<unsigned char, std::allocator<unsigned char> >; reference = unsigned char&]: Assertion '!this->empty()' failed.
```
