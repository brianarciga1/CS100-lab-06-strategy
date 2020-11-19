#ifndef __OP2_TEST_HPP__
#define __OP2_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "../lab-04/add.hpp"
#include "../lab-04/mult.hpp"
#include "../lab-04/power.hpp"
#include "../lab-04/sub.hpp"
#include "../lab-04/div.hpp"
#include "../lab-04/rand.hpp"
#include "container.hpp"
#include "../src/ListContainer.cpp"
#include "sort.hpp"
#include "../src/SelectionSort.cpp"

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
/////////////////////////////////////
TEST(ListContainerTestSet, AddElementTest) {
    ListContainer* test = new ListContainer();
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


TEST(ListContainerTestSet, AtTest) {
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);

    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(ListContainerTestSet, SwapTest) {
    Op* seven = new Op(7);
    Op* three = new Op(3);
    Op* ten = new Op(10);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(three);
    test_container->add_element(ten);

    test_container->swap(0, 2);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 10);
    EXPECT_EQ(test_container->at(2)->evaluate(), 7);
}

TEST(SortTestSet, SelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);
    
    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);

}

#endif //__OP2_TEST_HPP__

