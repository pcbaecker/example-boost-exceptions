cmake_minimum_required(VERSION 3.12)
project(example_boost_exceptions)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE( Boost 1.67 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(example_boost_exceptions main.cpp File.cpp File.h)

TARGET_LINK_LIBRARIES(example_boost_exceptions LINK_PUBLIC ${Boost_LIBRARIES} )