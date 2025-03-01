cmake_minimum_required (VERSION 3.28)
include(FetchContent)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# dependencies
find_package(OpenGL REQUIRED)
# glad
FetchContent_Declare(glad
	DOWNLOAD_EXTRACT_TIMESTAMP OFF
	URL https://github.com/Dav1dde/glad/archive/refs/tags/v2.0.8.zip
)
FetchContent_GetProperties(glad)
if (NOT glad_POPULATED)
	set(FETCHCONTENT_QUIET NO)
	FetchContent_MAkeAvailable(glad)
	add_subdirectory(${glad_SOURCE_DIR}/cmake glad_cmake)
	GLAD_ADD_LIBRARY(glad REPRODUCIBLE EXCLUDE_FROM_ALL LOADER API gl:core=4.6)
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
		set(FETCHCONTENT_QUIET NO)
		FetchContent_Populate(glm)
		add_subdirectory(${glm_SOURCE_DIR} ${glm_BINARY_DIR})
	endif()
endif()

project ("Ignis")

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/build")
set(THIRDPARTY_DIR "${CMAKE_SOURCE_DIR}/Ignis/ThirdParty")


# set include dirs
set(INCLUDE_DIRS 
	${CMAKE_SOURCE_DIR}/Ignis/Editor/src
	${CMAKE_SOURCE_DIR}/Ignis/Engine/src
  ${THIRDPARTY_DIR}/SDL3/include
  ${THIRDPARTY_DIR}/STB
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)
set(CAMKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/archive)

add_subdirectory ("Ignis/Editor/")
add_subdirectory ("Ignis/Engine/")

add_subdirectory("Ignis/ThirdParty/SDL3")
