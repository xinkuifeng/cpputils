#include <gtest/gtest.h>
#include <unordered_set>

#include <Point.h>

namespace fxk { namespace testing {

TEST(PointTest, testEqual) {
    Point p1(1, 2);
    Point p2(1, 2);

    EXPECT_TRUE(p1 == p2);
}

TEST(PointTest, testNotEqual) {
    Point p1(1, 2);
    Point p2(2, 1);

    EXPECT_TRUE(p1 != p2);
}

TEST(PointTest, testAdditionOne) {
    Point p1(1, 2);
    Point p2(2, 1);

    EXPECT_EQ(Point(3, 3), p1 + p2);
}

TEST(PointTest, testAdditionTwo) {
    Point p1(1, 2);
    Point p2(2, 1);

    EXPECT_EQ(Point(3, 3), p1 += p2);
}

TEST(PointTest, testSubtractionOne) {
    Point p1(1, 2);
    Point p2(2, 1);

    EXPECT_EQ(Point(1, -1), p2 - p1);
}

TEST(PointTest, testSubtractionTwo) {
    Point p1(1, 2);
    Point p2(2, 1);

    EXPECT_EQ(Point(1, -1), p2 -= p1);
}

TEST(PointTest, testHashCanFind) {
    Point p1(1, 2);

    std::unordered_set<Point> st;
    st.insert(p1);
    EXPECT_TRUE(st.find(p1) != st.end());
}

TEST(PointTest, testHashCannotFind) {
    Point p1(1, 2);
    Point p2(2, 1);

    std::unordered_set<Point> st;
    st.insert(p1);
    EXPECT_TRUE(st.find(p2) == st.end());
}

}}
