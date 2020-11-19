#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"

class Add : public Op {
    protected:
        Base* left;
	Base* right;
    public:
        Add(Base* value1, Base* value2) { 
	    left = value1;
	    right = value2;
	}
       	virtual double evaluate() { return (left->evaluate() + right->evaluate()); }
        virtual std::string stringify() {
	    return left->stringify() + "+" + right->stringify();
	}
};

#endif
