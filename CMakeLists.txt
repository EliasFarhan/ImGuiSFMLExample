cmake_minimum_required(VERSION 3.3)
project(ImguiExample)


set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

include_directories(include ${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE ImguiExample_SRC src/*.cpp include/*.h)

#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(SFML_BUILD_EXAMPLES FALSE)
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)
LIST(APPEND ImguiExample_LIBRARIES
	sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)

#SFML Imgui
set(SFML_IMGUI ${EXTERNAL_DIR}/imgui-sfml/)
set(IMGUI_ROOT ${EXTERNAL_DIR}/imgui/)

set(SFML_ROOT ${EXTERNAL_DIR}/SFML/)
add_subdirectory(${SFML_IMGUI})
include_directories(${IMGUI_ROOT} ${SFML_IMGUI})
LIST(APPEND ImguiExample_LIBRARIES 
	imgui-sfml)



#JSON
set(JSON_DIR ${EXTERNAL_DIR}/json/)
add_subdirectory(${JSON_DIR})
include_directories(${JSON_DIR}/src/)
LIST(APPEND ImguiExample_LIBRARIES
	nlohmann_json)


#ImguiExample
if(NOT WIN32)
LIST(APPEND ImguiExample_LIBRARIES
  stdc++fs)
ENDIF()

include_directories(include/)

add_executable(ImguiExample ${ImguiExample_SRC}) 
target_link_libraries(ImguiExample PUBLIC ${ImguiExample_LIBRARIES})

