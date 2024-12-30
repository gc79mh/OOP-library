cmake_minimum_required(VERSION 3.10)
project(Library)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add Google Test
find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
  message(FATAL_ERROR "Google Test not found!")
endif()

# Add your source files
set(SOURCES
  ./src/Book.cpp
  ./src/Member.cpp
  ./src/User.cpp
)

set(TESTS
  ./tests/BookTest.cpp
  ./tests/MemberTest.cpp
)

# Main application executable
add_executable(essa ${SOURCES} ./src/main.cpp)

# Test executable
add_executable(essa_tests ${TESTS} ${SOURCES})

# Link Google Test for the tests
target_link_libraries(essa_tests GTest::GTest GTest::Main pthread)

# Enable testing with CTest
enable_testing()
add_test(NAME BookTests COMMAND tests)
