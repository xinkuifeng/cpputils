cmake_minimum_required(VERSION 3.14)
project(cpputils)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
# Fetch release 1.12.0 (June 27, 2022)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)
add_subdirectory(tst)
