#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "../header/container.hpp"
#include "../header/base.hpp"
#include "../header/sort.hpp"
#include <list>
#include <iostream>
using std::list;
using namespace std;

class ListContainer : public Container
{
    protected:
        list<Base*> container;
        Base* child;
    public:
        ListContainer(): child(nullptr) {}
        ListContainer(Sort* temp): child(nullptr)
	{
	    sort_function = temp;
	} 
	void add_element(Base* element)
	{
	    container.push_back(element);
	}
	void print()
	{
	    list<Base*>::iterator it;
	       for(it = container.begin(); it != container.end(); it++) 
	           {
		        Base* a = *it;
			cout << a->stringify() << endl;
		   }
	}
        void sort()
        {
             sort_function->sort(this);
        }

	void swap(int i,int j)
	{
	   list<Base*>::iterator it;
	   int counter = 0;
	   Base* temp1;
	   Base* temp2;
	   int counter2 = 0;

	      for(it = container.begin(); it != container.end(); it++) 
	         {
		     if(counter == i)
		        {
			   temp1 = *it;
			}
		     if(counter == j)
			{
			   temp2 = *it;
			}
		      counter++;
		      counter2++;
		  }
	   counter = 0;
	   counter2 = 0;
	       for(it = container.begin(); it != container.end(); it++) 
		  {
		      if(counter == i)
			{
			    *it = temp2;
			}
		      if(counter == j)
			{
			    *it = temp1;
			}
		       counter++;
		       counter2++;
		  }
	}
	Base* at(int i)
	    {
	         list<Base*>::iterator it;
	         int counter = 0;
	         for(it = container.begin(); it != container.end(); it++) 
		    {
		         if(counter == i)
			    {
				return *it;
			    }
				counter++;
		    }
			return *it;
	     }
	int size()
	    {
			return container.size();
            }
};

#endif	
