cmake_minimum_required (VERSION 3.8.0)

#include path
include_directories("../../ProudNet/include")

#Setting the name of groups of files
file(GLOB SRC_MARSHAL
		*.cpp
		*.h
		*.rc)

#Setting the target
add_library(GameMarshal STATIC
			${SRC_MARSHAL})
set_property(TARGET GameMarshal PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set_property(TARGET GameMarshal PROPERTY ARCHIVE_OUTPUT_NAME GameMarshal)

#Setting about MSVC
# if(MSVC)
# 	foreach(PIDL_FILE ${PIDL_COMMON})
# 		get_filename_component(PFNAME ${PIDL_FILE} NAME_WE)
# 		add_custom_command(
# 			OUTPUT ${PFNAME}_common.cpp ${PFNAME}_common.h ${PFNAME}_proxy.cpp ${PFNAME}_proxy.h ${PFNAME}_stub.cpp ${PFNAME}_stub.h
# 			MAIN_DEPENDENCY ${PIDL_FILE}
# 			COMMAND ../../ProudNet/util/PIDL.exe
# 			ARGS ${PIDL_FILE})
# 	endforeach(PIDL_FILE)
# else(MSVC)
# 	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
# endif(MSVC)

