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

TEST(SegmentTest, testFullyContains) {
    Segment s1(2, 8);
    Segment s2(3, 7);

    EXPECT_TRUE(s1.fully_contains(s2));
    EXPECT_FALSE(s2.fully_contains(s1));
}

TEST(SegmentTest, testFullyContainsTwo) {
    Segment s1(6, 6);
    Segment s2(4, 6);

    EXPECT_FALSE(s1.fully_contains(s2));
    EXPECT_TRUE(s2.fully_contains(s1));
}

TEST(SegmentTest, testFullyContainsWithInvalidSegments) {
    Segment s1(2, 8);
    Segment s2(7, 3);

    EXPECT_FALSE(s1.fully_contains(s2));
    EXPECT_FALSE(s2.fully_contains(s1));
}

TEST(SegmentTest, testOverlapCaseOne) {
    Segment s1(2, 6);
    Segment s2(4, 8);

    EXPECT_TRUE(s1.overlap(s2));
    EXPECT_TRUE(s2.overlap(s1));
}

TEST(SegmentTest, testOverlapCaseTwo) {
    Segment s1(2, 8);
    Segment s2(3, 7);

    EXPECT_TRUE(s1.overlap(s2));
    EXPECT_TRUE(s2.overlap(s1));
}

TEST(SegmentTest, testOverlapCaseThree) {
    Segment s1(6, 6);
    Segment s2(4, 6);

    EXPECT_TRUE(s1.overlap(s2));
    EXPECT_TRUE(s2.overlap(s1));
}

TEST(SegmentTest, testNoOverlap) {
    Segment s1(2, 3);
    Segment s2(4, 5);

    EXPECT_FALSE(s1.overlap(s2));
    EXPECT_FALSE(s2.overlap(s1));
}

}}
