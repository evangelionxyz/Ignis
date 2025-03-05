cmake_minimum_required (VERSION 3.28)
include(FetchContent)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
  add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# GLM
find_package(glm 1.0.1 QUIET)
if (NOT glm_FOUND)
	FetchContent_Declare(glm
		DOWNLOAD_EXTRACT_TIMESTAMP OFF
		URL https://github.com/g-truc/glm/archive/refs/tags/1.0.1.zip
	)
	FetchContent_GetProperties(glm)
	if (NOT glm_POPULATED)
		FetchContent_MakeAvailable(glm)
	endif()
endif()

if (WIN32)
	add_definitions(-DPLATFORM_WINDOWS)

	if(NOT DEFINED ENV{VULKAN_SDK})
		message(FATAL_ERROR
				">> VULKAN_SDK environment variable not defined. Please install the Vulkan SDK and set the environment variable.")
	endif()

	set(VULKAN_INCLUDE_DIR $ENV{VULKAN_SDK}/Include)
	set(VULKAN_LIBRARY_DIR $ENV{VULKAN_SDK}/Lib)

	message(">> Platform: Win32")
	message(">> Vulkan include dir: ${VULKAN_INCLUDE_DIR}")
	message(">> Vulkan lib dir: ${VULKAN_LIBRARY_DIR}")

	# Enable Hot Reload for MSVC compilers if supported.
	if (POLICY CMP0141)
		cmake_policy(SET CMP0141 NEW)
		set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
				$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>
		)
	endif()
elseif (UNIX AND NOT APPLE)
	# Check if we're running in WSL
	execute_process(COMMAND uname -r OUTPUT_VARIABLE WSL_KERNEL_NAME)
	string(FIND "${WSL_KERNEL_NAME}" "Microsoft" WSL_FOUND)

	if (WSL_FOUND EQUAL -1)
		message(">> Platform: WSL")
	else()
		message(">> Platform: LINUX")
	endif()

	add_definitions(-DPLATFORM_LINUX)
endif()

project ("Ignis")

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build")
set(THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/Ignis/ThirdParty")


# set include dirs
set(INCLUDE_DIRS
		${CMAKE_SOURCE_DIR}/Ignis/Editor/src
		${CMAKE_SOURCE_DIR}/Ignis/Engine/src
		${THIRDPARTY_DIR}/SDL3/include
		${THIRDPARTY_DIR}/IMGUI
		${THIRDPARTY_DIR}/STB
		${THIRDPARTY_DIR}/SPDLOG/include
		${THIRDPARTY_DIR}/GLAD/include
		${VULKAN_INCLUDE_DIR}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/archive)

add_subdirectory ("Ignis/Editor/")
add_subdirectory ("Ignis/Engine/")
add_subdirectory("Ignis/ThirdParty/SDL3")
add_subdirectory("Ignis/ThirdParty/SPDLOG")

include("Ignis/ThirdParty/THIRDPARTY.cmake")
