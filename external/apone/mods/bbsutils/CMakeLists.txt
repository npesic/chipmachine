cmake_minimum_required(VERSION 3.12.0)
project(cpp-mods.bbsutils)

add_subdirectory(../netlink netlink)
#add_subdirectory(../coreutils coreutils)
include_directories(../netlink ..)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES
	ansiconsole.cpp
	console.cpp
	editor.cpp
	petsciiconsole.cpp
	telnetserver.cpp
	# localconsole.cpp is now built on every platform: it carries both the POSIX
	# (termios) terminal and a Win32 console backend, so Console::createLocalConsole()
	# is defined on Windows too (previously it was excluded here and returned null).
	localconsole.cpp
)

add_library(bbsutils ${SOURCE_FILES})
target_link_libraries(bbsutils netlink coreutils)

#add_executable(bbstest test.cpp)
#target_link_libraries(bbstest bbsutils coreutils)
