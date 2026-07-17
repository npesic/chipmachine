 cmake -B builds/release -G Ninja -DCMAKE_BUILD_TYPE=Release
-- The C compiler identification is GNU 16.1.0
-- The CXX compiler identification is GNU 16.1.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/msys64/mingw64/bin/cc.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/msys64/mingw64/bin/c++.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Freetype: C:/msys64/mingw64/lib/libfreetype.dll.a (found version "2.14.3")
-- Found OpenGL: opengl32
CMake Warning (author) at external/apone/mods/grappix/CMakeLists.txt:62 (find_package):
  The module name

    Findglew.cmake

  does not match the case of the module file name on disk

    C:/msys64/mingw64/share/cmake/Modules/FindGLEW.cmake

  This may fail on case-sensitive file systems.  Use the module name

    FindGLEW.cmake

  instead.
This warning is for project developers.  Use -Wno-author to suppress it.

CMake Warning (author) at C:/msys64/mingw64/share/cmake/Modules/FindPackageHandleStandardArgs.cmake:493 (message):
  The package name passed to find_package_handle_standard_args() (GLEW) does
  not match the name of the calling package (glew).  This can lead to
  problems in calling code that expects find_package() result variables
  (e.g., `_FOUND`) to follow a certain pattern.
Call Stack (most recent call first):
  C:/msys64/mingw64/share/cmake/Modules/Findglew.cmake:316 (find_package_handle_standard_args)
  external/apone/mods/grappix/CMakeLists.txt:62 (find_package)
This warning is for project developers.  Use -Wno-author to suppress it.

-- Could NOT find GLEW (missing: GLEW_INCLUDE_DIRS GLEW_LIBRARIES)
CMake Error at external/apone/mods/grappix/CMakeLists.txt:63 (find_library):
  Could not find GLFW_LIBRARY using the following names: libglfw3.a, glfw3,
  glfw3dll


-- Configuring incomplete, errors occurred!
