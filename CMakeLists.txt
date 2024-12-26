cmake_minimum_required(VERSION 3.10)
project(UnitTests)

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files
set(SOURCES
  ./library/src/hello.cpp    
)
   
add_executable(essa ${SOURCES})

# Link Google Test
target_link_libraries(essa ${GTEST_LIBRARIES} pthread)

