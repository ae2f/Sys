option(ae2f_TEST "" ON)
option(ae2f_MAC_BUILD "" ON)
option(ae2f_IS_SHARED "" ON)
option(ae2f_DEVEL ""	ON)

enable_testing()

cmake_minimum_required(VERSION 3.10)
project(Sys VERSION 0.0.0)

include(cmake/Core.cmake)

if(ae2f_MAC_BUILD)
	function(ae2f_itll tar)
		target_link_libraries(${tar} ${ARGN})
	endfunction()
else()
	function(ae2f_itll tar)
		target_link_libraries(${tar} INTERFACE ${ARGN})
	endfunction()
endif()

if(NOT TARGET ae2f::Sys)
	ae2f_CoreLibFetchX(ae2f Core	main)
	ae2f_CoreLibFetchX(ae2f Preproc	main)
	ae2f_CoreLibFetchX(ae2f	c89atomic master)

	file(GLOB_RECURSE sys-inc inc/ae2f/Sys/*)

	ae2f_Macro_init(1 30 30)
	ae2f_Macro_Lib_V(
		ae2f Sys "${ae2f_LIBPREFIX}" 
		${PROJECT_SOURCE_DIR}/src/sys "*.imp.c" 
		${PROJECT_SOURCE_DIR}/src/sys "*.def.cc" 
		${PROJECT_SOURCE_DIR}/inc/ae2f/Sys ".auto.h"
		${PROJECT_SOURCE_DIR}/Config/Sys.cmake.in inc
		inc/ae2f/Sys.h ${sys-inc}
		)

	install(TARGETS c89atomic c89atomic_common
		EXPORT ae2f-SysTargets
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		)

	ae2f_itll(${ae2f__Sys__TENT} ae2f::Core)
	ae2f_itll(${ae2f__Sys__TENT} ae2f::Preproc)
	ae2f_itll(${ae2f__Sys__TENT} c89atomic)

	ae2f_CoreTestTent(${ae2f__Sys__TENT} test/primal)
endif()
