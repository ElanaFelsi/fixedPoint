#include "TestPrice.h"
#include "color.h"
#include "number2word.h"
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
    FixedPoint<9, char> fixedPoint5 (0, 8);
    std::cout << fixedPoint5;
    FixedPoint<4, int> fixedPoint6(1);
    std::cout << fixedPoint6;
}

TEST(FPTest, selfPlus)
{
    FixedPoint<9, int> fixedPoint1(2, 077777);
    FixedPoint<9, int> fixedPoint2(1, 037777);
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

TEST(FPTest, arrayOfColor)
{
    FixedPoint<2, int> fp(2, 0);
    Color color;
    Color* arr = color.calcFixedPointGradient(fp);
    //std::cout << sizeof(arr)/ sizeof(arr[0]);
    std::cout << color.getSizeArr(fp);
}

TEST(FPTest, asString)
{
    FixedPoint<2, int> fp(2, 0);
    std::cout << fp.asString();
}

TEST(FPTest, digits2word)
{
    std::string e = "123.45";
    std::cout << digitsToWord(e, 0, 2);
}

TEST(FPTest, number2word)
{
    FixedPoint<2, int> fp(200, 0);
    ASSERT_TRUE(numberToWords(fp.getMInteger())== "Two Hundred ");
}

TEST(FPTest, theType)
{
    FixedPoint<2, int>::theType var;
    ASSERT_TRUE(sizeof(int) == sizeof(var));

}