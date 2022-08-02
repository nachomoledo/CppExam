cmake_minimum_required(VERSION 3.0.0)
project(CppExam VERSION 0.1.0)

include(CTest)
enable_testing()

cmake_minimum_required(VERSION 3.12)

include_directories(${PROJECT_SOURCE_DIR}/inc/)

file(GLOB SOURCES src/*.cpp)

add_executable(CppExam ${SOURCES})

#target_compile_features(CppExam PUBLIC cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#target_include_directories(CppExam PUBLIC
#                          "${PROJECT_BINARY_DIR}"
#                          "${PROJECT_SOURCE_DIR}/src"
#                          )