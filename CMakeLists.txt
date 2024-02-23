cmake_minimum_required(VERSION 3.0.0)
project(process_api VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(1_fork_with_flags 1_fork_with_flags.cpp)
add_executable(2_fork_opened_file 2_fork_opened_file.cpp)
add_executable(3_fork_with_barrier 3_fork_with_barrier.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME} -g)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION} -g)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g") 
include(CPack)
