#ifndef __POWER_HPP__
#define __POWER_HPP__

#include "base.hpp"
#include "op.hpp"
#include <math.h>

class Power : public Op {
    protected:
        Base* left;
        Base* right;
    public:
        Power(Base* value1, Base* value2) {
            left = value1;
            right = value2;
        }
        virtual double evaluate() { return pow(left->evaluate(), right->evaluate()); }
        virtual std::string stringify() {
            return left->stringify() + "**" + right->stringify();
        }
};

#endif

