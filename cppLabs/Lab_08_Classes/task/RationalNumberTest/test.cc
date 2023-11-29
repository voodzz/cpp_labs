#include "gtest/gtest.h"
#include "../RationalNumber.h"

TEST(ClassRationalNumberTest, TestSum) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber c(7, 5);

    EXPECT_EQ(a + c, RationalNumber(1, 1));
    EXPECT_EQ(a + 1, RationalNumber(3, 5));
    EXPECT_EQ(a + b + c, RationalNumber(3, 2));
    EXPECT_EQ(a + (-a), RationalNumber(0, 1));
    EXPECT_EQ(a + RationalNumber(), a);
    EXPECT_EQ(b + 0, b);
}

TEST(ClassRationalNumberTest, TestSubstraction) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber c(7, 5);
    RationalNumber zero;

    EXPECT_EQ(a - c, RationalNumber(-9, 5));
    EXPECT_EQ(a - 1, RationalNumber(-7, 5));
    EXPECT_EQ(c - b - a, RationalNumber(13, 10));
    EXPECT_EQ(a - (-a), RationalNumber(-4, 5));
    EXPECT_EQ(a - zero, a);
    EXPECT_EQ(b - 0, b);
}

TEST(ClassRationalNumberTest, TestMultiplication) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber c(7, 5);
    RationalNumber zero;

    EXPECT_EQ(a * c, RationalNumber(-14, 25));
    EXPECT_EQ(a * 3, RationalNumber(-6, 5));
    EXPECT_EQ(a * b * c, RationalNumber(-7, 25));
    EXPECT_EQ(a * (-a), RationalNumber(-4, 25));
    EXPECT_EQ(a * zero, zero);
    EXPECT_EQ(b * 0, zero);
}

TEST(ClassRationalNumberTest, TestDivisionPositive) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber c(7, 5);
    RationalNumber zero;

    EXPECT_EQ(a / c, RationalNumber(-2, 7));
    EXPECT_EQ(a / 3, RationalNumber(-2, 15));
    EXPECT_EQ(a / (b / c), RationalNumber(-28, 25));
    EXPECT_EQ(a / a, RationalNumber(1, 1));
    EXPECT_EQ(a / (-a), RationalNumber(-1, 1));
    EXPECT_EQ(zero / c, zero);
}

TEST(ClassRationalNumberTest, TestDivisionNegative) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber zero;

    ASSERT_THROW(a / zero, std::invalid_argument);
    ASSERT_THROW(b / 0, std::invalid_argument);
}

TEST(ClassRationalNumberTest, TestComparison) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber zero;

    EXPECT_TRUE(a < zero);
    EXPECT_TRUE(b >= zero);
    EXPECT_TRUE(b == RationalNumber(1, 2));
    EXPECT_TRUE(a == a);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(b > a);
    EXPECT_TRUE(b >= a);
}
