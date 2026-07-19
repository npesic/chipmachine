cmake_minimum_required(VERSION 3.12.0)
project(cpp-mods.grappix)

file(GLOB MAIN_FILES grappix/*.cpp grappix/gui/*.cpp)
file(GLOB FREETYPE_FILES grappix/freetype-gl/*.c)
set(SOURCE_FILES ${MAIN_FILES} ${FREETYPE_FILES})

file(GLOB SPECIFIC_FILES grappix/specific/*.cpp)
add_custom_target(grappix.specific_files SOURCES ${SPECIFIC_FILES})

if(NOT TARGET image)
  add_subdirectory(../image image)
endif()

if(NOT TARGET tween)
  add_subdirectory(../tween tween)
endif()

if(NOT TARGET coreutils)
	add_subdirectory(../coreutils coreutils)
endif()

# 1. Force CMake to inspect Apple Silicon Homebrew paths natively
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
endif()

# 2. Modernized system discovery 
find_package(Freetype REQUIRED)

# 3. Handle the include tracking cleanly
if(FREETYPE_FOUND)
    include_directories(${FREETYPE_INCLUDE_DIRS})
endif()

if(APPLE)
  find_library(COCOA_LIBRARY Cocoa)
  find_library(CORE_VIDEO_LIBRARY CoreVideo)
  find_library(IOKIT_LIBRARY IOKit)
  set(EXTRA_LIBS ${EXTRA_LIBS} ${COCOA_LIBRARY} ${CORE_VIDEO_LIBRARY} ${IOKIT_LIBRARY})
endif()

set(OpenGL_GL_PREFERENCE GLVND)

if(EMSCRIPTEN)
  
  set(SOURCE_FILES ${SOURCE_FILES} grappix/specific/window_pc.cpp)
  set(EXTRA_LIBS ${EXTRA_LIBS} -lGL)

elseif(RASPBERRY)

  set(VC ${PI_SYS_ROOT}/vc)
  set(SOURCE_FILES ${SOURCE_FILES} grappix/specific/window_pi.cpp grappix/specific/eglutil.cpp)
  set(EXTRA_LIBS ${EXTRA_LIBS} EGL GLESv2 vcos vchiq_arm bcm_host)
  include_directories(${VC}/include ${VC}/include/interface/vcos/pthreads ${VC}/include/interface/vmcs_host/linux)

elseif(WIN32)

  # Windows uses the same generic desktop backend as Linux/Emscripten: GLFW for
  # the window and input, GLEW for GL entry points. There is no Win32-specific
  # window code -- GLFW abstracts it.
  set(SOURCE_FILES ${SOURCE_FILES} grappix/specific/window_pc.cpp)

  find_package(OpenGL REQUIRED)

  # Uppercase GLEW = CMake's FindGLEW *module*, which is what defines
  # GLEW_INCLUDE_DIRS / GLEW_LIBRARIES and the GLEW::GLEW imported target.
  # `find_package(glew)` (lowercase) searches *config* mode for a
  # glew-config.cmake instead and leaves all of those unset -- it can therefore
  # "succeed" while silently contributing no include path and no library.
  find_package(GLEW REQUIRED)

  # Shared (DLL) linkage. MSYS2's glfw package ships both libglfw3.a (static)
  # and libglfw3dll.a (the import library for glfw3.dll); prefer the import
  # library. Static GLFW additionally requires pulling in gdi32/user32/shell32
  # by hand, and static GLEW requires -DGLEW_STATIC; mixing either with a DLL
  # build is a classic source of missing/duplicate __imp_* symbols. Shared keeps
  # the link simple. glfw3.dll / glew32.dll resolve from /mingw64/bin inside the
  # MINGW64 shell; for distribution they must be copied beside the executable.
  find_library(GLFW_LIBRARY NAMES glfw3dll glfw3 REQUIRED)

  set(EXTRA_LIBS ${EXTRA_LIBS} ${OPENGL_LIBRARIES})
  include_directories(${OPENGL_INCLUDE_DIRS})

  set(EXTRA_LIBS ${EXTRA_LIBS} GLEW::GLEW)

  set(EXTRA_LIBS ${EXTRA_LIBS} ${GLFW_LIBRARY})

  # Win32 plumbing the GL/window stack needs regardless of static vs shared.
  set(EXTRA_LIBS ${EXTRA_LIBS} gdi32 user32 shell32)


elseif(UNIX)
  set(SOURCE_FILES ${SOURCE_FILES} grappix/specific/window_pc.cpp)
  find_package(OpenGL REQUIRED)

  if(APPLE)
    find_library(GLFW_LIBRARY NAMES glfw REQUIRED)
  else() # Ubuntu changed naming between 14.0 and 14.10
    find_library(GLFW_LIBRARY NAMES libglfw.so.3 libglfw3.a REQUIRED)
  endif()

  set(EXTRA_LIBS ${EXTRA_LIBS} ${OPENGL_LIBRARIES})
  include_directories(${OPENGL_INCLUDE_DIRS})
  set(EXTRA_LIBS ${EXTRA_LIBS} ${GLFW_LIBRARY})
  find_library(GLEW_LIBRARY GLEW REQUIRED)
  set(EXTRA_LIBS ${EXTRA_LIBS} ${GLEW_LIBRARY})

  if(NOT APPLE)
    if(GLFW_LIBRARY MATCHES "\\.a")
      message("GLFW is static")
      set(EXTRA_LIBS ${EXTRA_LIBS} -lX11 -lXxf86vm -lXrandr -lpthread -lXi -lXinerama -lXcursor)
    else()
      message("GLFW is dynamic")
      set(EXTRA_LIBS ${EXTRA_LIBS} -lX11 -lXxf86vm -lpthread)
    endif()
  endif()

else()
endif()

add_definitions(-DWITH_FREETYPE)

file(GLOB SHADERS grappix/shaders/*.glsl)

add_custom_target(grappix.shaders SOURCES ${SHADERS})

# Embed each shader as a C array. This used to shell out to `xxd -i` with a `>`
# redirect, which requires vim and a POSIX shell -- neither is available in a
# default MSYS2/Windows environment. bin2c.cmake does the same with plain CMake.
#
# The symbol name must stay exactly what xxd produced from the path
# ".shader/<name>", because grappix/shader.cpp declares the symbols by hand
# (e.g. `extern unsigned char _shader_plain_v_glsl[];`). xxd maps every
# non-alphanumeric character to '_', so ".shader/plain_v.glsl" became
# "_shader_plain_v_glsl" -- reproduced below.
foreach(SHADER ${SHADERS})
	get_filename_component(SHADERNAME ${SHADER} NAME)
	string(REGEX REPLACE "[^a-zA-Z0-9]" "_" SHADERSYM "${SHADERNAME}")
	set(SHADERSYM "_shader_${SHADERSYM}")
	add_custom_command(OUTPUT ${SHADERNAME}.c
		COMMAND ${CMAKE_COMMAND}
			-DINPUT=${SHADER}
			-DOUTPUT=${CMAKE_CURRENT_BINARY_DIR}/${SHADERNAME}.c
			-DSYMBOL=${SHADERSYM}
			-P ${CMAKE_CURRENT_SOURCE_DIR}/bin2c.cmake
		DEPENDS ${SHADER} ${CMAKE_CURRENT_SOURCE_DIR}/bin2c.cmake
		COMMENT "Embedding shader ${SHADERNAME} -> ${SHADERSYM}"
		VERBATIM)
	set(SOURCE_FILES ${SOURCE_FILES} ${SHADERNAME}.c)
endforeach()

include_directories(.. grappix/freetype-gl)

add_library(grappix ${SOURCE_FILES})
target_link_libraries(grappix coreutils image tween Freetype::Freetype  ${EXTRA_LIBS})
target_include_directories(grappix PRIVATE ..)
