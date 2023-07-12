cmake_minimum_required (VERSION 3.8.0)

#include path
include_directories("../../ProudNet/include")

#Setting the name of groups of files
file(GLOB SRC_CLIENT
		*.cpp
		*.h)

#Setting the target
add_executable(GameClient ${SRC_CLIENT})
add_dependencies(GameClient GameCommon)
set_property(TARGET GameClient PROPERTY OUTPUT_DIRECTORY ../bin)
set_property(TARGET GameClient PROPERTY OUTPUT_NAME Client)

if(MSVC) #Setting about MSVC
	if(${CMAKE_VS_PLATFORM_TOOLSET} STRGREATER_EQUAL "v140")
		set(VS_VERSION_FOLDER_NAME "v140")
	else()
		set(VS_VERSION_FOLDER_NAME ${CMAKE_VS_PLATFORM_TOOLSET})
	endif()
	
	target_link_libraries(GameClient ../../../ProudNet/lib/${CMAKE_VS_PLATFORM_NAME}/${VS_VERSION_FOLDER_NAME}/${CMAKE_CFG_INTDIR}/ProudNetClient)
	target_link_libraries(GameClient ../../bin/${CMAKE_CFG_INTDIR}/GameCommon)
	target_link_libraries(GameClient ../../bin/${CMAKE_CFG_INTDIR}/GameMarshal)
else(MSVC)#Setting about None-Windows 
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
	target_link_libraries(GameClient
		${CMAKE_CURRENT_SOURCE_DIR}/../../../ProudNet/lib/x86_x64-linux/Release/libProudNetClient.a
#		${CMAKE_CURRENT_SOURCE_DIR}/../../../ProudNet/lib/x86_x64-linux/Release/libProudNetClient.so
		${CMAKE_CURRENT_SOURCE_DIR}/../../bin/libGameCommon.a
		${CMAKE_CURRENT_SOURCE_DIR}/../../bin/libGameMarshal.a
	)
endif(MSVC)