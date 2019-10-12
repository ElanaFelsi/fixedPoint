#include "TestPrice.h"
#include <gtest/gtest.h>

TEST(PriceTest, CTOR_Price)
{
    Price p1(5);
    Price p2(3, 50);
    Price p3(-3, 50);
    ASSERT_TRUE(p1.getPrice() == 500);
    ASSERT_TRUE(p2.getPrice() == 350);
    ASSERT_TRUE(p3.getPrice() == -250);
}


TEST(PriceTest, assignmentOpr)
{
    Price p1(5);
    Price p2(3, 50);
    p1 = p2;
    ASSERT_TRUE(p1.getPrice() == 350);
    p2 = 1;
    ASSERT_TRUE(p2.getPrice() == 100);
}

TEST(PriceTest, BoolOverloadOpr)
{
    Price p1(5);
    Price p2(5, 5);
    ASSERT_TRUE(p1 != p2);
    ASSERT_FALSE(p1 == p2);
    ASSERT_TRUE(p1 < p2);
}

TEST(PriceTest, OverloadOpr)
{
    Price p1(5);
    Price p2(1);
    p1 += p2;
    ASSERT_EQ(p1, 600);
    p1 -= p2;
    ASSERT_EQ(p1, 500);
    p1 *= p2;
    ASSERT_EQ(p1, 500);
    p1 /= p2;
    ASSERT_EQ(p1, 500);

}
