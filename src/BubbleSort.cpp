#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "../header/sort.hpp"
#include "../header/container.hpp"

class BubbleSort : public Sort {
    public:
	BubbleSort() : Sort() {};
	void sort(Container* container) {
	    for (int i = 0; i < container->size(); i++) {
		for (int j = 0; j < container->size() - 1; j++) {
		    if(container->at(j)->evaluate() > container->at(j+1)->evaluate()){
			container->swap(j, j+1);
		    }
		}
	    }
	};
};

#endif
