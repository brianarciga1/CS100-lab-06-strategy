#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "../header/container.hpp"
//#include "../header/sort.hpp"
//#include "../header/base.hpp"
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

class VectorContainer : public Container {
    protected:
	vector <Base*> container;
	Base* child;
    public:
	VectorContainer(): child(nullptr) {};
	VectorContainer(Sort* temp): child(nullptr) {
	    sort_function = temp;
	};

	void add_element(Base* element) {
	    container.push_back(element);
	};

	void print() {
	    vector<Base*> temp = container;
	    for(int i = 0; i < container.size(); i++){
		cout << temp[i]->stringify() << endl;
	    }
	};

	void sort() {
	    sort_function->sort(this);
	};

	void swap(int i, int j) {
	    Base* temp = container[i];
	    container[i] = container[j];
	    container[j] = temp;
	};

	Base* at(int i) {
	    return container[i];
	};

	int size() {
	    return container.size();
	};	
};

#endif	
