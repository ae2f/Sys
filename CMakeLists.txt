option(ae2f_TEST "" ON)
option(ae2f_MAC_BUILD "" 	ON)
option(ae2f_IS_SHARED "" 	ON)
option(ae2f_Sys_DEVEL ""	OFF)

if(${ae2f_Sys_DEVEL})
	set(HELPER_LINK PUBLIC)
else()
	set(HELPER_LINK INTERFACE)
endif()

enable_testing()

cmake_minimum_required(VERSION 3.10)
project(Sys VERSION 0.0.0 LANGUAGES C CXX)

# Set this source directory as the tree root for project.
set(ae2f_ProjRoot ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Tree root for project")
set(ae2f_submod  .submod CACHE STRING "Relative path to submodule (subdirectory)")
set(ae2f_CoreScript_Wh ${ae2f_ProjRoot}/${ae2f_submod}/ae2f/CoreScript)

# Execute git to fetch CoreScript when repository does not exist
if(NOT EXISTS ${ae2f_CoreScript_Wh})
	execute_process(
		COMMAND git clone https://codeberg.org/ae2f/CoreScript
		${ae2f_CoreScript_Wh}
		)
endif()

# add subdirectory
if(NOT TARGET ae2f::CoreScript)
	add_subdirectory(${ae2f_CoreScript_Wh} ${ae2f_submod}/ae2f/CoreScript)
endif()

# FIXME
if(NOT TARGET ae2f::SysCore)
	ae2f_CoreLibFetchX(ae2f Preproc	main)
	ae2f_CoreLibFetchX(ae2f Core	main)

	ae2f_CoreLibTentConfigCustom(
		SysCore INTERFACE inc ae2f 
		${PROJECT_SOURCE_DIR}/Config/Sys-Base.cmake.in
		)

	if(WIN32)
		target_link_libraries(${ae2f__SysCore__TENT} INTERFACE ws2_32)
	endif()
endif()

if(NOT TARGET ae2f::Sys)
	ae2f_CoreLibFetchX(ae2f	c89atomic master)
	file(GLOB_RECURSE sys-inc ${PROJECT_SOURCE_DIR}/inc/)
	file(GLOB_RECURSE sys-src ${PROJECT_SOURCE_DIR}/src/*)

	ae2f_Macro_init(1 30 30)
	if(${ae2f_Sys_DEVEL})
		message(STATUS "ae2f::Sys Developer mode")
		ae2f_Macro_Lib_V(
			ae2f Sys STATIC
			${PROJECT_SOURCE_DIR}/src/sys "*.def.c" 
			${PROJECT_SOURCE_DIR}/src/sys "*.def.c" 
			${PROJECT_SOURCE_DIR}/inc/ae2f/Sys ".auto.h"
			${PROJECT_SOURCE_DIR}/Config/Sys.cmake.in 
			inc
			inc/ae2f/Sys.h ${sys-inc} ${sys-src}
			)
	else()
		ae2f_Macro_Lib_V(
			ae2f Sys INTERFACE 
			${PROJECT_SOURCE_DIR}/src/sys "*.imp.c" 
			${PROJECT_SOURCE_DIR}/src/sys "*.def.c" 
			${PROJECT_SOURCE_DIR}/inc/ae2f/Sys ".auto.h"
			${PROJECT_SOURCE_DIR}/Config/Sys.cmake.in 
			inc
			inc/ae2f/Sys.h ${sys-inc}
			)
	endif()

	install(
		TARGETS c89atomic c89atomic_common
		EXPORT SysTargets
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		)

	target_link_libraries(${ae2f__Sys__TENT} ${HELPER_LINK} ae2f::Core)
	target_link_libraries(${ae2f__Sys__TENT} ${HELPER_LINK} ae2f::SysCore)
	target_link_libraries(${ae2f__Sys__TENT} ${HELPER_LINK} ae2f::Preproc)
	target_link_libraries(${ae2f__Sys__TENT} ${HELPER_LINK} c89atomic)

	ae2f_CoreTestTentVerbose(${ae2f__Sys__TENT} test/primal)
	ae2f_CoreTestTentVerbose(${ae2f__Sys__TENT} test/enums)
endif()
