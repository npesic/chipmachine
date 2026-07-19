cmake -S . -B builds/release -DCM_GUI=ON       -U 'GLEW*' -U 'glew*' -U GLFW_LIBRARY
-- Building for: Ninja
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
-- Found GLEW: C:/msys64/mingw64/lib/cmake/glew/glew-config.cmake
-- Performing Test HAS_NO_PIE
-- Performing Test HAS_NO_PIE - Success
-- Found ZLIB: C:/msys64/mingw64/lib/libz.dll.a (found version "1.3.2")
CMake Error at external/musicplayer/src/plugins/sksplugin/arkostracker3/JUCE/CMakeLists.txt:41 (include):
  include could not find requested file:

    extras/Build/CMake/JUCEModuleSupport.cmake


CMake Error at external/musicplayer/src/plugins/sksplugin/arkostracker3/JUCE/modules/CMakeLists.txt:24 (juce_add_modules):
  Unknown CMake command "juce_add_modules".


-- Configuring incomplete, errors occurred!
