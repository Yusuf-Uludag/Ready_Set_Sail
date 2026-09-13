cmake_minimum_required(VERSION 3.28)

project(ready_set_sail VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(Raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
    URL_HASH SHA256=2b3ee1e2120c7a0796b33062c7e9a694dd8a8caa56a96319ac8c8ecf54a90d0b
    SYSTEM
)
FetchContent_MakeAvailable(Raylib)

add_subdirectory(src/)

if (EMSCRIPTEN)

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")

    add_custom_target(webpage
        COMMAND ${EMSCRIPTEN_ROOT_PATH}/emrun --hostname localhost --port 6931 --browser helium --no-emrun-detect "$<TARGET_FILE:${PROJECT_NAME}>"
        USES_TERMINAL
        VERBATIM
    )

endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)