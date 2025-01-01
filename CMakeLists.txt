cmake_minimum_required(VERSION 3.10)
project(Library)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Debugging
set(CMAKE_BUILD_TYPE Debug)

# Add debugging and sanitizer flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fsanitize=address")

# Find Google Test
find_package(GTest REQUIRED)
if(NOT GTest_FOUND)
  message(FATAL_ERROR "Google Test not found!")
endif()

# Enable warnings for GCC/Clang
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Werror -Wnon-virtual-dtor)
endif()

# Enable warnings for MSVC
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_compile_options(/W4 /WX)
endif()

# Source files
set(SOURCES
  ./src/DebugPrinter.cpp
  ./src/Book.cpp
  ./src/User.cpp
  ./src/Member.cpp
  ./src/Library.cpp
  ./src/Worker.cpp
  ./src/Boss.cpp
  ./src/LoginManager.cpp
  ./src/MainSession.cpp
  ./src/Utils.cpp
  ./src/MemberSession.cpp
  ./src/Session.cpp
  ./src/WorkerSession.cpp
  ./src/BossSession.cpp
)

# Test files
set(TESTS
  ./tests/BookTest.cpp
  ./tests/MemberTest.cpp
  ./tests/LibraryTest.cpp
  ./tests/LoginTest.cpp
)

# Main application executable
add_executable(essa ${SOURCES} ./src/main.cpp)

# Test executable
add_executable(essa_tests ${TESTS} ${SOURCES})

# Link Google Test for the tests
target_link_libraries(essa_tests GTest::GTest GTest::Main pthread)
