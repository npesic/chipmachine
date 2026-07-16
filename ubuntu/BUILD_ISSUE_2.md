# Ubuntu Build Issue 2

```
CMake Error at /usr/share/cmake-3.22/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find Freetype (missing: FREETYPE_LIBRARY FREETYPE_INCLUDE_DIRS)
Call Stack (most recent call first):
  /usr/share/cmake-3.22/Modules/FindPackageHandleStandardArgs.cmake:594 (_FPHSA_FAILURE_MESSAGE)
  /usr/share/cmake-3.22/Modules/FindFreetype.cmake:162 (find_package_handle_standard_args)
  external/apone/mods/grappix/CMakeLists.txt:29 (find_package)


-- Configuring incomplete, errors occurred!
See also "/mnt/c/Users/lab/git/chipmachine/builds/release/CMakeFiles/CMakeOutput.log".
ninja: Entering directory `builds/release'
ninja: error: loading 'build.ninja': No such file or directory
```
