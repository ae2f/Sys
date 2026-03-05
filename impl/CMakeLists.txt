cmake_minimum_required(VERSION 3.10)
enable_testing()

# =================

project(SysFtx VERSION 0)
ae2f_Macro_Lib_V2(
	ae2f SysFtx INTERFACE 
	${PROJECT_SOURCE_DIR}/src/ftx		"NOTHING" 
	${PROJECT_SOURCE_DIR}/src/ftx		"*.c" 
	${PROJECT_SOURCE_DIR}/inc/ae2f/Sys/.ftx	".h"
	${PROJECT_SOURCE_DIR}/../cfg/SysFtx.cmake.in 
	inc ON
	)

target_link_libraries(ae2f-SysFtx INTERFACE ae2f::SysFtxCore)
ae2f_CoreTestTentVerbose(ae2f-SysFtx ${PROJECT_SOURCE_DIR}/test/ftx)

# =================
project(SysThrd		VERSION 0)
ae2f_Macro_Lib_V2(
	ae2f SysThrd INTERFACE 
	${PROJECT_SOURCE_DIR}/src/thrd			"NOTHING" 
	${PROJECT_SOURCE_DIR}/src/thrd			"*.c" 
	${PROJECT_SOURCE_DIR}/inc/ae2f/Sys/.thrd	".h"
	${PROJECT_SOURCE_DIR}/../cfg/SysThrd.cmake.in 
	inc ON
	)
target_link_libraries(ae2f-SysThrd INTERFACE ae2f::SysThrdCore)
ae2f_CoreTestTentVerbose(ae2f-SysThrd ${PROJECT_SOURCE_DIR}/test/thrd)

# =================
project(SysSock		VERSION 0)
ae2f_Macro_Lib_V2(
	ae2f SysSock INTERFACE 
	${PROJECT_SOURCE_DIR}/src/sock			"NOTHING" 
	${PROJECT_SOURCE_DIR}/src/sock			"*.c" 
	${PROJECT_SOURCE_DIR}/inc/ae2f/Sys/.sock	".h"
	${PROJECT_SOURCE_DIR}/../cfg/SysSock.cmake.in 
	inc ON
	)
target_link_libraries(ae2f-SysSock INTERFACE ae2f::SysInetCore)

# =================
project(SysInet		VERSION 0)
ae2f_Macro_Lib_V2(
	ae2f SysInet INTERFACE 
	${PROJECT_SOURCE_DIR}/src/inet			"NOTHING" 
	${PROJECT_SOURCE_DIR}/src/inet			"*.c" 
	${PROJECT_SOURCE_DIR}/inc/ae2f/Sys/.inet	".h"
	${PROJECT_SOURCE_DIR}/../cfg/SysInet.cmake.in 
	inc ON
	)
target_link_libraries(ae2f-SysInet INTERFACE ae2f::SysSock)

# =================
project(SysInet		VERSION 0)
ae2f_Macro_Lib_V2(
	ae2f SysTrm INTERFACE 
	${PROJECT_SOURCE_DIR}/src/trm			"NOTHING" 
	${PROJECT_SOURCE_DIR}/src/trm			"*.c" 
	${PROJECT_SOURCE_DIR}/inc/ae2f/Sys/.trm		".h"
	${PROJECT_SOURCE_DIR}/../cfg/SysTrm.cmake.in 
	inc ON
	)
target_link_libraries(ae2f-SysTrm INTERFACE ae2f::SysCore)
