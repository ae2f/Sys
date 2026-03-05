cmake_minimum_required(VERSION 3.10)
enable_testing()

set(ae2f_ProjRoot ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Tree root for project")
set(ae2f_BinRoot ${CMAKE_CURRENT_BINARY_DIR} CACHE STRING "Tree root for project")
set(ae2f_submod  .submod CACHE STRING "Relative path to submodule (subdirectory)")
set(ae2f_Preproc_Wh ${ae2f_ProjRoot}/${ae2f_submod}/ae2f/Preproc)
option(ae2f_TEST	ON ON)

# Execute git to fetch CoreScript when repository does not exist
if(NOT EXISTS ${ae2f_Preproc_Wh})
	execute_process(
		COMMAND git clone https://codeberg.org/ae2f/Preproc
		${ae2f_Preproc_Wh}
		)
endif()

# add subdirectory
if(NOT TARGET ae2f::Preproc)
	add_subdirectory(${ae2f_Preproc_Wh} ${ae2f_submod}/ae2f/Preproc)
endif()

# ==========================
if(NOT TARGET ae2f::Sys)
	ae2f_CoreLibFetchX(ae2f Core main)
	ae2f_CoreLibFetchX(ae2f Pat master)

	ae2f_Macro_init(1 30 100)

	project(SysCore VERSION 0)
	file(GLOB_RECURSE ae2f-core-inc ${PROJECT_SOURCE_DIR}/inc/*)

	ae2f_CoreLibTentConfigCustom(
		SysCore INTERFACE inc ae2f
		${PROJECT_SOURCE_DIR}/cfg/SysCore.cmake.in
		${ae2f-core-inc}
		)

	target_link_libraries(ae2f-SysCore INTERFACE ae2f::Pat)

	# =============================
	project(SysThrdCore	VERSION 0)
	ae2f_CoreLibTentConfigCustom(
		SysThrdCore INTERFACE inc ae2f
		${PROJECT_SOURCE_DIR}/cfg/SysThrdCore.cmake.in
		)

	ae2f_CoreLibFetch(ae2f c89atomic master)
	target_link_libraries(ae2f-SysThrdCore INTERFACE ae2f::SysCore INTERFACE c89atomic)
	install(
		TARGETS c89atomic c89atomic_common
		EXPORT SysThrdCoreTargets
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		)

	if(WIN32 OR MINGW OR CYGWIN OR LINUX)
	else()
		target_link_libraries(ae2f-SysThrdCore INTERFACE pthread)
	endif()

	# =============================

	project(SysFtxCore	VERSION 0)
	ae2f_CoreLibTentConfigCustom(
		SysFtxCore INTERFACE inc ae2f
		${PROJECT_SOURCE_DIR}/cfg/SysFtxCore.cmake.in
		)

	target_link_libraries(ae2f-SysFtxCore INTERFACE ae2f::SysCore)

	if(WIN32 OR MINGW OR CYGWIN)
		target_link_libraries(ae2f-SysFtxCore INTERFACE Synchronization)
	endif()

	# =============================

	project(SysInetCore	VERSION 0)
	ae2f_CoreLibTentConfigCustom(
		SysInetCore INTERFACE inc ae2f
		${PROJECT_SOURCE_DIR}/cfg/SysInetCore.cmake.in
		)

	if(WIN32 OR MINGW OR CYGWIN)
		target_link_libraries(ae2f-SysInetCore INTERFACE ws2_32)
	endif()

	# =============================

	add_subdirectory(impl)
	ae2f_CoreLibTentConfigCustom(
		Sys INTERFACE inc ae2f
		${PROJECT_SOURCE_DIR}/cfg/Sys.cmake.in
		)

	target_link_libraries(
		ae2f-Sys	INTERFACE
		ae2f::SysFtx
		ae2f::SysThrd
		ae2f::SysInet
		ae2f::SysSock
		ae2f::SysTrm
		)

	ae2f_CoreTestTentVerbose(ae2f-Sys test)
endif()
