#include "TestPrice.h"
#include <gtest/gtest.h>


TEST(FPTest, CTOR_FP)
{
    FixedPoint<2, int> fixedPoint1 (1, 50);
    std::cout << fixedPoint1;
    FixedPoint<2, int> fixedPoint2 (1, 03);
    std::cout << fixedPoint2;
    FixedPoint<2, int> fixedPoint3 (-1, 50);
    std::cout << fixedPoint3;
    FixedPoint<2, int> fixedPoint4 (0, -04);
    std::cout << fixedPoint4;
    FixedPoint<9, char> fixedPoint5 (0, 5678);
    std::cout << fixedPoint5;
    FixedPoint<4, int> fixedPoint6(1);
    std::cout << fixedPoint6;
}

TEST(PriceTest, selfPlus)
{
    FixedPoint<2, int> fixedPoint1(2, 07);
    FixedPoint<2, int> fixedPoint2(1, 03);
    fixedPoint1 += fixedPoint2;
    std::cout << fixedPoint1;

    FixedPoint<2, int> fixedPoint3(2, 70);
    FixedPoint<2, int> fixedPoint4(1, 30);
    fixedPoint3 += fixedPoint4;
    std::cout << fixedPoint3;

    FixedPoint<2, int> fixedPoint5(-2);
    FixedPoint<2, int> fixedPoint6(1, 50);
    fixedPoint5 += fixedPoint6;
    std::cout << fixedPoint5;
}

/*
TEST(PriceTest, CTOR_Price)
{
    Price<int, 2> p1(5);
    Price<int, 2> p2(3, 50);
    Price<int, 2> p3(-3, 50);
    ASSERT_TRUE(p1.getPrice() == 500);
    ASSERT_TRUE(p2.getPrice() == 350);
    ASSERT_TRUE(p3.getPrice() == -250);
}


TEST(PriceTest, assignmentOpr)
{
    Price<int, 2> p1(5);
    Price<int, 2> p2(3, 50);
    p1 = p2;
    ASSERT_TRUE(p1.getPrice() == 350);
    p2 = 1;
    ASSERT_TRUE(p2.getPrice() == 100);
}

TEST(PriceTest, CmpOpr)
{
    Price<int, 2> p1(5);
    Price<int, 2> p2(5, 5);
    ASSERT_TRUE(p1 != p2);
    ASSERT_FALSE(p1 == p2);
    ASSERT_TRUE(p1 < p2);
}

TEST(PriceTest, arithmeticOpr)
{
    Price<int, 2> p1(5);
    Price<int, 2> p2(1);

    ASSERT_EQ(p1 += p2, 600);
    ASSERT_EQ(p1 -= p2, 500);
    ASSERT_EQ(p1 *= p2, 500);
    ASSERT_EQ(p1/=p2, 500);
    ASSERT_EQ(++p2, 200);
    //std::cout << p2.T2double();
}

TEST(PriceTest, phaseII)
{
    Price<short, 2> mySalary(120, 35);
    ASSERT_TRUE(mySalary.getPrice() == 12035);

    Price<long, 2> myOverdraft(99999, 99);
    ASSERT_TRUE(myOverdraft.getPrice() == 9999999);

    Price<long long, 2> useSelfDebt(145800000000000);
    ASSERT_TRUE(useSelfDebt.getPrice() == 14580000000000000);

    //myOverdraft = mySalary

}
*/