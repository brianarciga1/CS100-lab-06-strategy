#include <iostream>

#include "../lab-04/base.hpp"
#include "../lab-04/op.hpp"
#include "../lab-04/add.hpp"
#include "../lab-04/mult.hpp"
#include "../lab-04/power.hpp"
#include "../lab-04/sub.hpp"
#include "../lab-04/div.hpp"
#include "../header/container.hpp"
#include "VectorContainer.cpp"
#include "../header/sort.hpp"
#include "BubbleSort.cpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;

    VectorContainer* container = new VectorContainer();
    container->add_element(three);
    container->add_element(seven);
    container->add_element(two);
    container->print();    

    return 0;
}
