file(GLOB SRCS *.cc)
add_executable(cpputils_tst ${SRCS})
target_link_libraries(cpputils_tst PRIVATE gtest gmock gtest_main)
