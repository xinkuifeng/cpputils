#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include <AocUtils.h>

using ::testing::ContainerEq;

namespace fxk { namespace testing {

TEST(LongParserTest, testParseLong) {
    std::string line = "-2147483649, 2147483648";

    std::vector<long> res = parse_long(line);
    std::vector<long> exp{2147483649, 2147483648};

    EXPECT_THAT(res, ContainerEq(exp));
}

TEST(LongParserTest, testParseLongWithNegative) {
    std::string line = "-2147483649, 2147483648";

    std::vector<long> res = parse_long(line, true);
    std::vector<long> exp{-2147483649, 2147483648};

    EXPECT_THAT(res, ContainerEq(exp));
}

}}
