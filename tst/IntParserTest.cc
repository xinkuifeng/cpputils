#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include <AocUtils.h>

using ::testing::ContainerEq;

namespace fxk { namespace testing {

TEST(IntParserTest, testParseIntFormatOne) {
    std::string line = "2-4,6-8";

    std::vector<int> res = parse_int(line);
    std::vector<int> exp{2, 4, 6, 8};

    EXPECT_THAT(res, ContainerEq(exp));
}

TEST(IntParserTest, testParseIntFormatOneWithNegatives) {
    std::string line = "2-4,6-8";

    std::vector<int> res = parse_int(line, true);
    std::vector<int> exp{2, -4, 6, -8};

    EXPECT_THAT(res, ContainerEq(exp));
}

TEST(IntParserTest, testParseIntFormatTwo) {
    std::string line = "1, -2, 3";

    std::vector<int> res = parse_int(line);
    std::vector<int> exp{1, 2, 3};

    EXPECT_THAT(res, ContainerEq(exp));
}

TEST(IntParserTest, testParseIntFormatTwoWithNegatives) {
    std::string line = "1, -2, 3";

    std::vector<int> res = parse_int(line, true);
    std::vector<int> exp{1, -2, 3};

    EXPECT_THAT(res, ContainerEq(exp));
}

TEST(IntParserTest, testParseIntFormatThree) {

    std::string line = std::string("Blueprint 1: Each ore robot costs 4 ore. ") +
        std::string("Each clay robot costs 4 ore. Each obsidian robot costs 4 ore and 17 clay. ")
        + std::string("Each geode robot costs 4 ore and 20 obsidian.");

    std::vector<int> res = parse_int(line);
    std::vector<int> exp{1, 4, 4, 4, 17, 4, 20};

    EXPECT_THAT(res, ContainerEq(exp));
}

}}
