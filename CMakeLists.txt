cmake_minimum_required(VERSION 3.14)
project(TetrisProjesi)

set(CMAKE_CXX_STANDARD 17)

set(SFML_BUILD_AUDIO ON CACHE INTERNAL "Build SFML Audio module")

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(SFML)

add_executable(tetris main.cpp OyunAlani.cpp TetrisBloklari.cpp BilgiAlani.cpp)

target_include_directories(tetris PRIVATE ${sfml_SOURCE_DIR}/include)

target_link_libraries(tetris sfml-graphics sfml-window sfml-system sfml-audio)

if(WIN32)
    add_custom_command(TARGET tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:tetris>
        $<TARGET_FILE_DIR:tetris>
        COMMAND_EXPAND_LISTS
    )
endif()