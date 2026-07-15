# Localize the STRONG (GLOBAL, non-weak), HIDDEN, DEFINED symbols of an object.
#
# Invoked (via `cmake -P`) after the `ld -r` partial link of the plugins that
# bundle vendored emulator cores under -fvisibility=hidden. Those cores collide
# with identically-named cores in other plugins at final link, so they must be
# made file-local. A plain `objcopy --localize-hidden` would also localize the
# *weak* COMDAT symbols (C++ template/inline instantiations, vtables), which
# breaks COMDAT section-group deduplication at final link ("defined in discarded
# section"). Selecting only GLOBAL (non-weak) hidden symbols avoids that: the
# emulator cores are ordinary strong symbols, the COMDAT entries are weak.
#
# Required -D arguments: OBJ (object to edit), OBJCOPY, READELF.
#   (OBJCOPY/READELF come from ${CMAKE_OBJCOPY}/${CMAKE_READELF}, so this is
#    correct for the cross toolchain too.)

execute_process(
    COMMAND ${READELF} -sW ${OBJ}
    OUTPUT_VARIABLE _out
    RESULT_VARIABLE _rc)
if(NOT _rc EQUAL 0)
    message(FATAL_ERROR "readelf failed on ${OBJ} (rc=${_rc})")
endif()

# readelf -sW symbol lines: "Num: Value Size Type Bind Vis Ndx Name".
# Keep GLOBAL + HIDDEN with a numeric section index (defined; excludes UND/ABS).
string(REPLACE "\n" ";" _lines "${_out}")
set(_names "")
foreach(_l IN LISTS _lines)
    if(_l MATCHES "GLOBAL[ \t]+HIDDEN[ \t]+[0-9]+[ \t]+([^ \t]+)")
        list(APPEND _names "${CMAKE_MATCH_1}")
    endif()
endforeach()

if(_names)
    list(REMOVE_DUPLICATES _names)
    string(REPLACE ";" "\n" _content "${_names}")
    file(WRITE "${OBJ}.localize" "${_content}\n")
    execute_process(
        COMMAND ${OBJCOPY} --localize-symbols=${OBJ}.localize ${OBJ}
        RESULT_VARIABLE _rc2)
    if(NOT _rc2 EQUAL 0)
        message(FATAL_ERROR "objcopy --localize-symbols failed on ${OBJ} (rc=${_rc2})")
    endif()
endif()
