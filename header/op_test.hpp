#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "../lab-04/add.hpp"
#include "../lab-04/mult.hpp"
#include "../lab-04/power.hpp"
#include "../lab-04/sub.hpp"
#include "../lab-04/div.hpp"
#include "container.hpp"
#include "../src/VectorContainer.cpp"
#include "sort.hpp"
#include "../src/BubbleSort.cpp"

TEST(OpTest, OpStringifyNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}

TEST(OpTest, OpEvaluateNegative) {
    Op* test = new Op(-8);
    EXPECT_EQ(test->evaluate(), -8);
}

TEST(OpTest, OpStringifyNegative) {
    Op* test = new Op(-8);
    EXPECT_EQ(test->stringify(), "-8.000000");
}

TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(OpTest, OpStringifyZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->stringify(), "0.000000");
}


TEST(AddTest, AddEvaluateNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Add(eight,five); 
    EXPECT_EQ(test->evaluate(), 13);
}

TEST(AddTest, AddStringifyNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Add(eight,five);
    EXPECT_EQ(test->stringify(), "8.000000+5.000000");
}

TEST(AddTest, AddEvaluateZero) {
    Base* zero = new Op(0);
    Base* zero2 = new Op(0);
    Base* test = new Add(zero,zero2);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(AddTest, AddStringifyZero) {
    Base* zero = new Op(0);
    Base* zero2 = new Op(0);
    Base* test = new Add(zero,zero2);
    EXPECT_EQ(test->stringify(), "0.000000+0.000000");
}

TEST(AddTest, AddEvaluateNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Add(eight,five);
    EXPECT_EQ(test->evaluate(), -3);
}

TEST(AddTest, AddStringifyNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Add(eight,five);
    EXPECT_EQ(test->stringify(), "-8.000000+5.000000");
}


TEST(MultTest, MultEvaluateNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Mult(eight,five);
    EXPECT_EQ(test->evaluate(), 40);
}

TEST(MultTest, MultStringifyNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Mult(eight,five);
    EXPECT_EQ(test->stringify(), "8.000000*5.000000");
}

TEST(MultTest, MultEvaluateZero) {
    Base* zero = new Op(0);
    Base* five = new Op(5);
    Base* test = new Mult(zero,five);
    EXPECT_EQ(test->evaluate(), 0);
}

TEST(MultTest, MultStringifyZero) {
    Base* zero = new Op(0);
    Base* five = new Op(5);
    Base* test = new Mult(zero,five);
    EXPECT_EQ(test->stringify(), "0.000000*5.000000");
}

TEST(MultTest, MultEvaluateNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(5);
    Base* test = new Mult(eight,five);
    EXPECT_EQ(test->evaluate(), -40);
}

TEST(MultTest, MultStringifyDoubleNegative) {
    Base* eight = new Op(-8);
    Base* five = new Op(-5);
    Base* test = new Mult(eight,five);
    EXPECT_EQ(test->stringify(), "-8.000000*-5.000000");
}


TEST(PowTest, PowEvaluateNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Power(eight,five);
    EXPECT_EQ(test->evaluate(), 32768);
}

TEST(PowTest, PowStringifyNonZero) {
    Base* eight = new Op(8);
    Base* five = new Op(5);
    Base* test = new Power(eight,five);
    EXPECT_EQ(test->stringify(), "8.000000**5.000000");
}

TEST(PowTest, PowEvaluateZeroExponent) {
    Base* eight = new Op(8);
    Base* zero = new Op(0);
    Base* test = new Power(eight,zero);
    EXPECT_EQ(test->evaluate(), 1);
}

TEST(PowTest, PowStringifyZeroExponent) {
    Base* eight = new Op(8);
    Base* zero = new Op(0);
    Base* test = new Power(eight,zero);
    EXPECT_EQ(test->stringify(), "8.000000**0.000000");
}

TEST(PowTest, PowEvaluateNegativeExponent) {
    Base* eight = new Op(8);
    Base* two = new Op(-2);
    Base* test = new Power(eight,two);
    EXPECT_NEAR(test->evaluate(), 0.01, 0.02);
}

TEST(PowTest, PowStringifyNegativeExponent) {
    Base* eight = new Op(8);
    Base* two = new Op(-2);
    Base* test = new Power(eight,two);
    EXPECT_EQ(test->stringify(), "8.000000**-2.000000");
}

TEST(VectorContainerTestSet, AddElementTest) {
    VectorContainer* test = new VectorContainer();
    Op* one = new Op(1);
    test->add_element(one);

    EXPECT_EQ(test->size(), 1);

    testing::internal::CaptureStdout();
    test->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1.000000\n");
}

/*TEST(VectorContainerTestSet, PrintTest) {
    Op* seven = new Op(7);
    Op* one = new Op(1);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    test_container->add_element(one);

    ASSERT_EQ(test_container->size(), 1);
    testing::internal::CaptureStdout();
    test_container->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "7.000000\n1.000000\n");
}*/


TEST(VectorContainerTestSet, AtTest) {
    Op* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);

    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainerTestSet, SwapTest) {
    Op* seven = new Op(7);
    Op* three = new Op(3);
    Op* ten = new Op(10);
    VectorContainer* test_container = new VectorContainer();

    test_container->add_element(seven);
    test_container->add_element(three);
    test_container->add_element(ten);

    test_container->swap(0, 2);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 10);
    EXPECT_EQ(test_container->at(2)->evaluate(), 7);
}

TEST(SortTestSet, BubbleSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);
    
    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);

}

#endif //__OP_TEST_HPP__
