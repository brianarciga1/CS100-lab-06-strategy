#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "../header/sort.hpp"
#include "../header/container.hpp"

using namespace std;

class SelectionSort : public Sort
{
    public:
	void sort(Container* container)
	{
	    int i,j,first;
	    int numLength = container->size();
	    for(i = numLength -1; i >0; i--)
		{
		    first = 0;
		    for(j = 1; j <= i; j++)
			{
			    if(container->at(j)->evaluate() < container->at(first)->evaluate())
			        {
				    first = j;
				}
			}
		    container->swap(first, i);	
		}
	}
};

#endif
