cmake_minimum_required(VERSION 3.10)
project(SFML-Tutorial LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE source_files "src/*.cpp")

set(SOURCES ${source_files})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE "src" "engine")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_custom_command(
    TARGET ${PROJECT_NAME}
    COMMENT "Copy Res directory"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
    VERBATIM)

# Run the application after build
#add_custom_command(
#    TARGET ${PROJECT_NAME}
#    COMMENT "Run ${PROJECT_NAME}"
#    POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_NAME}>
#    VERBATIM)
#

