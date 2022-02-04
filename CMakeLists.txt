cmake_minimum_required(VERSION 3.5.1)
set (CMAKE_CXX_STANDARD 17)
project(TTS_CPP VERSION 0.1.0)

include(CTest)
enable_testing()

set(TRANSFORMER_DIR TransformerTTS-Cpp)
add_subdirectory(${TRANSFORMER_DIR})

add_executable(TTS_CPP main.cpp)

set(Torch_DIR TransformerTTS-Cpp/libtorch/share/cmake/Torch)
find_package(Torch REQUIRED)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

target_link_libraries(
    TTS_CPP
    TransformerTTS-CPP
#    ${TORCH_LIBRARIES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)