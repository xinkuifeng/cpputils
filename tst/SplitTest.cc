#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include <AocUtils.h>

using ::testing::ContainerEq;

namespace fxk { namespace testing {

TEST(SplitTest, testSplitByWhitespaceOne) {
    std::string input1("$ cd /");
    std::string input2("$   cd   /");

    std::vector<std::string> res = split(input1, ' ');
    std::vector<std::string> exp{"$", "cd", "/"};

    EXPECT_THAT(res, ContainerEq(exp));

    res = split(input2, ' ');
    EXPECT_THAT(res, ContainerEq(exp));
}

TEST(SplitTest, testSplitByWhitespaceTwo) {
    std::string input("1234 c.dat");

    std::vector<std::string> res = split(input, ' ');
    std::vector<std::string> exp{"1234", "c.dat"};

    EXPECT_THAT(res, ContainerEq(exp));
}

}}

