#ifndef __OP2_TEST_HPP__
#define __OP2_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "rand.hpp"
#include "div.hpp"
#include "sub.hpp"

TEST(RandTest, RandEvaluateGreater) {
    Rand* test = new Rand();
    int eval = 0;
    if (test->evaluate() == 200)
        eval = -1;
    else
        eval = 1;
    EXPECT_EQ(1, eval);
}

TEST(RandTest, RandStringifyGreater) {
    Rand* test = new Rand();
    int eval = 0;
    if (test->stringify() == "200")
        eval = -1;
    else
        eval = 1;
    EXPECT_EQ(1, eval);
}

TEST(RandTest, RandEvaluateNegative) {
    Rand* test = new Rand();
    int eval = 0;
    if (test->evaluate() == -10)
        eval = -1;
    else
        eval = 1;
    EXPECT_EQ(1, eval);
}

TEST(RandTest, RandStringifyNegative) {
    Rand* test = new Rand();
    int eval = 0;
    if (test->stringify() == "-10")
        eval = -1;
    else
        eval = 1;
    EXPECT_EQ(1, eval);
}

TEST(RandTest, RandEvaluateDefault) {
    Rand* test = new Rand();
    int eval = 0;
    if (test->evaluate() != 50 )
        eval = -1;
    else
        eval = 1;
    EXPECT_EQ(-1, eval);
}

TEST(RandTest, RandStringifyDefault) {
    Rand* test = new Rand();
    int eval = 0;
    if (test->stringify() != "50")
        eval = -1;
    else
        eval = 1;
    EXPECT_EQ(-1, eval);
}

TEST(DivTest, DivEvaluateNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Div(eight,five);
    EXPECT_EQ(test->evaluate(), 1.6);
}

TEST(DivTest, DivStringifyNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Div(eight,five);
    EXPECT_EQ(test->stringify(), "8.000000/5.000000");
}

TEST(DivTest, DivEvaluateZero) {
    Base* zero = new Op(0);
    Base* five = new Op(5);
    Base* test = new Div(zero,five);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(DivTest, DivStringifyZero) {
    Base* zero = new Op(0);
    Base* five = new Op(5);
    Base* test = new Div(zero,five);
    EXPECT_EQ(test->stringify(), "0.000000/5.000000");
}

TEST(DivTest, DivEvaluateNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Div(eight,five);
    EXPECT_EQ(test->evaluate(), -1.6);
}

TEST(DivTest, DivStringifyDoubleNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Div(eight,five);
    EXPECT_EQ(test->stringify(), "-8.000000/5.000000");
}

TEST(SubTest, SubEvaluateNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Sub(eight,five); 
    EXPECT_EQ(test->evaluate(), 3);
}

TEST(SubTest, SubStringifyNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Sub(eight,five);
    EXPECT_EQ(test->stringify(), "8.000000-5.000000");
}

TEST(SubTest, SubEvaluateZero) {
    Base* zero = new Op(0);
    Base* zero2 = new Op(0);
    Base* test = new Sub(zero,zero2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(SubTest, SubStringifyZero) {
    Base* zero = new Op(0);
    Base* zero2 = new Op(0);
    Base* test = new Sub(zero,zero2);
    EXPECT_EQ(test->stringify(), "0.000000-0.000000");
}

TEST(SubTest, SubEvaluateNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Sub(eight,five);
    EXPECT_EQ(test->evaluate(), -13);
}

TEST(SubTest, SubStringifyNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Sub(eight,five);
    EXPECT_EQ(test->stringify(), "-8.000000-5.000000");
}
#endif //__OP_TEST_HPP__
