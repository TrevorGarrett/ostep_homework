cmake_minimum_required(VERSION 3.0.0)
project(process_api VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(process_api main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME} -g)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION} -g)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g") 
include(CPack)
