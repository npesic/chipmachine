# Build Issue 3

```
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Freetype: /usr/lib/x86_64-linux-gnu/libfreetype.so (found version "2.11.1")
-- Found OpenGL: /usr/lib/x86_64-linux-gnu/libOpenGL.so
GLFW is dynamic
-- Performing Test HAS_NO_PIE
-- Performing Test HAS_NO_PIE - Success
CMake Error at /usr/share/cmake-3.22/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find Boost (missing: Boost_INCLUDE_DIR)
Call Stack (most recent call first):
  /usr/share/cmake-3.22/Modules/FindPackageHandleStandardArgs.cmake:594 (_FPHSA_FAILURE_MESSAGE)
  /usr/share/cmake-3.22/Modules/FindBoost.cmake:2360 (find_package_handle_standard_args)
  external/musicplayer/src/plugins/zxtuneplugin/CMakeLists.txt:28 (find_package)


-- Configuring incomplete, errors occurred!
See also "/mnt/c/Users/lab/git/chipmachine/builds/release/CMakeFiles/CMakeOutput.log".
ninja: Entering directory `builds/release'
ninja: error: loading 'build.ninja': No such file or directory
```
