#include <gtest/gtest.h>
#include <unordered_set>

#include <Segment.h>

namespace fxk { namespace testing {

TEST(SegmentTest, testEqual) {
    Segment s1;
    Segment s2;

    EXPECT_TRUE(s1 == s2);
}

TEST(SegmentTest, testNotEqual) {
    Segment s1(1, 2);
    Segment s2(2, 3);

    EXPECT_TRUE(s1 != s2);
}

TEST(SegmentTest, testIsValid) {
    Segment s(1, 2);

    EXPECT_TRUE(s.valid());
}

TEST(SegmentTest, testIsNotValid) {
    Segment s(2, 1);

    EXPECT_FALSE(s.valid());
}

TEST(SegmentTest, testHashCanFind) {
    Segment s1(0, 1);
    Segment s2(0, 1);

    std::unordered_set<Segment> st;
    st.insert(s1);
    EXPECT_TRUE(st.find(s2) != st.end());
}

TEST(SegmentTest, testHashCannotFind) {
    Segment s1(1, 2);
    Segment s2(2, 1);

    std::unordered_set<Segment> st;
    st.insert(s1);
    EXPECT_TRUE(st.find(s2) == st.end());
}

}}
