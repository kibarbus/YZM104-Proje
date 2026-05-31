cmake_minimum_required(VERSION 3.14)
project(TetrisProjesi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_BUILD_AUDIO ON CACHE INTERNAL "Build SFML Audio module")

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(SFML)

add_executable(tetris src/main.cpp src/OyunAlani.cpp src/TetrisBloklari.cpp src/BilgiAlani.cpp)

target_link_libraries(tetris sfml-graphics sfml-window sfml-system sfml-audio)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

if(WIN32)
    add_custom_command(TARGET tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:tetris>
        $<TARGET_FILE_DIR:tetris>
        COMMAND_EXPAND_LISTS
    )
endif()