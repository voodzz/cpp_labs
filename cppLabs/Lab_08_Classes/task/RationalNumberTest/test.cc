#include "gtest/gtest.h"
#include "../RationalNumber.h"

TEST(ClassRationalNumberTest, TestSum) {
    RationalNumber a(-2, 5);
    RationalNumber b(5, 10);
    RationalNumber c(7, 5);

    EXPECT_EQ(a + c, RationalNumber(1, 2));
    EXPECT_EQ(a + 1, RationalNumber(3, 5));
    EXPECT_EQ(a + b + c, RationalNumber(3, 2));
    EXPECT_EQ(a + (-a), RationalNumber(0, 1));
    EXPECT_EQ(a + RationalNumber(), a);
    EXPECT_EQ(b + 0, b);
}
