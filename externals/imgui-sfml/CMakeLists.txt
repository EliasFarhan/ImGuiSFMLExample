# Only tested in 3.1, may work in older versions.
# .
# Install SFML or set SFML_ROOT and set IMGUI_ROOT prior to running cmake
# .
# Provides the follow variables:
# IMGUI_SFML_INCLUDE_DIRS - imgui and imgui_sfml include paths
# IMGUI_SOURCES - imgui.cpp source path to link with your binary
# IMGUI_SFML_SOURCES - imgui_sfml.cpp source path to link with your binary
# IMGUI_SFML_DEPENDENCIES - found dependencies to link with your library (sfml)
# .
# Sample usage:
#   add_subdirectory(repos/imgui-sfml)
#   include_directories("${IMGUI_SFML_INCLUDE_DIRS}")
#   add_executable(MY_PROJECT ${IMGUI_SOURCES} ${IMGUI_SFML_SOURCES} ${SRCS})
#   ...
#   target_link_libraries(MY_PROJECT ${IMGUI_SFML_DEPENDENCIES})
# .
# Define spine-sfml library
if(IMGUI_ROOT)
    set(IMGUI_SERACH_PATH
        ${IMGUI_ROOT}
        $ENV{IMGUI_ROOT}
        )
    find_path(IMGUI_INCLUDE_DIR imgui.cpp
              PATHS ${IMGUI_SERACH_PATH})
    if(NOT IMGUI_INCLUDE_DIR)
        message(FATAL_ERROR "---> IMGUI imgui.cpp not found. Set IMGUI_ROOT to imgui's top-level path (containing \"imgui.cpp\" and \"imgui.h\" files).\n")
    else()
        file(GLOB IMGUI_FILES
            "${IMGUI_INCLUDE_DIR}/imgui_draw.cpp"
            "${IMGUI_INCLUDE_DIR}/imgui_demo.cpp"
            "${IMGUI_INCLUDE_DIR}/imgui.cpp"
            "${IMGUI_INCLUDE_DIR}/imgui.h")
        include_directories(${IMGUI_INCLUDE_DIR})
        message("Found imgui.cpp in ${IMGUI_INCLUDE_DIR}")
        # Rename that pesky imconfig.h file for the user.
        install(FILES ${IMGUI_INCLUDE_DIR}/imconfig.h DESTINATION include RENAME imconfig-sample.h)
    endif()
endif()
file(GLOB_RECURSE INCLUDES "imgui-SFML.h" "imgui-config.h")
include_directories(${SFML_DIR}/include ${IMGUI}/include)
file(GLOB_RECURSE SOURCES "imgui-SFML.cpp")
add_definitions(-DSFML_STATIC)
add_library(imgui-sfml STATIC ${SOURCES} ${INCLUDES} ${IMGUI_FILES})
target_link_libraries(imgui-sfml sfml-graphics sfml-system sfml-window)
install(TARGETS imgui-sfml DESTINATION dist/lib)
install(FILES ${INCLUDES} DESTINATION dist/include)
