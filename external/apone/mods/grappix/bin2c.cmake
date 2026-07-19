# bin2c.cmake -- a portable replacement for `xxd -i`.
#
# The shader sources are embedded into the binary as C arrays. That was done by
# shelling out to `xxd -i` (a vim tool) with a `>` shell redirect, which needs
# vim installed and assumes a POSIX shell -- neither is a given on Windows/MSYS2.
# This does the same job with nothing but CMake.
#
# Invoke with:
#   cmake -DINPUT=<file> -DOUTPUT=<file.c> -DSYMBOL=<name> -P bin2c.cmake
#
# Output must match xxd's exactly, because grappix/shader.cpp declares the
# symbols by hand, e.g.:
#     extern unsigned char _shader_plain_v_glsl[];
#     extern int           _shader_plain_v_glsl_len;
# xxd derives that name from the path it is given (".shader/plain_v.glsl" ->
# "_shader_plain_v_glsl"), so the caller passes SYMBOL explicitly. xxd emits the
# length as `unsigned int`; shader.cpp declares it `int`. That mismatch is
# pre-existing and harmless at link time (same size, C linkage), so keep
# `unsigned int` to stay byte-compatible with the previous behaviour.

if(NOT DEFINED INPUT OR NOT DEFINED OUTPUT OR NOT DEFINED SYMBOL)
    message(FATAL_ERROR "bin2c: INPUT, OUTPUT and SYMBOL are all required")
endif()

file(READ "${INPUT}" _hex HEX)
string(LENGTH "${_hex}" _hexlen)
math(EXPR _len "${_hexlen} / 2")

if(_len EQUAL 0)
    # `unsigned char x[] = {};` is not valid C; emit a single NUL like xxd would
    # never produce but which keeps the translation unit compilable.
    set(_bytes "0x00")
    set(_len 0)
else()
    # One regex pass over the whole hex string is far faster than looping.
    string(REGEX REPLACE "(..)" "0x\\1, " _bytes "${_hex}")
endif()

file(WRITE "${OUTPUT}"
    "/* Generated from ${INPUT} by bin2c.cmake -- do not edit. */\n"
    "unsigned char ${SYMBOL}[] = { ${_bytes} };\n"
    "unsigned int ${SYMBOL}_len = ${_len};\n")
