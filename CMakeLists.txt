option(ae2f_TEST "" ON)
option(ae2f_MAC_BUILD "" ON)
option(ae2f_IS_SHARED "" ON)
option(ae2f_DEVEL ""	ON)

enable_testing()

cmake_minimum_required(VERSION 3.10)
project(Sys VERSION 0.0.0 LANGUAGES C CXX)

include(cmake/Core.cmake)

# FIXME
if(NOT TARGET ae2f::SysCore)
	ae2f_CoreLibFetchX(ae2f Preproc	main)
	ae2f_CoreLibFetchX(ae2f Core	main)

	ae2f_CoreLibTentConfigCustom(
		SysCore INTERFACE inc ae2f 
		${PROJECT_SOURCE_DIR}/Config/Sys-Base.cmake.in
		)

	if(WIN32)
		target_link_libraries(${ae2f__SysCore__TENT} ws2_32)
	endif()
endif()

if(NOT TARGET ae2f::Sys)
	ae2f_CoreLibFetchX(ae2f	c89atomic master)
	file(GLOB_RECURSE sys-inc ${PROJECT_SOURCE_DIR}/inc/)

	ae2f_Macro_init(1 30 30)
	ae2f_Macro_Lib_V(
		ae2f Sys INTERFACE
		${PROJECT_SOURCE_DIR}/src/sys "*.imp.c" 
		${PROJECT_SOURCE_DIR}/src/sys "*.def.c" 
		${PROJECT_SOURCE_DIR}/inc/ae2f/Sys ".auto.h"
		${PROJECT_SOURCE_DIR}/Config/Sys.cmake.in 
		inc
		inc/ae2f/Sys.h ${sys-inc}
		)

	install(
		TARGETS c89atomic c89atomic_common
		EXPORT ${ae2f__Sys__TENT}Targets
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		)

	target_link_libraries(${ae2f__Sys__TENT} INTERFACE ae2f::Core)
	target_link_libraries(${ae2f__Sys__TENT} INTERFACE ae2f::SysCore)
	target_link_libraries(${ae2f__Sys__TENT} INTERFACE ae2f::Preproc)
	target_link_libraries(${ae2f__Sys__TENT} INTERFACE c89atomic)

	ae2f_CoreTestTentVerbose(${ae2f__Sys__TENT} test/primal)
	ae2f_CoreTestTentVerbose(${ae2f__Sys__TENT} test/enums)
endif()
