#include "../header/container.hpp"
#include "../header/base.hpp"
#include "../header/sort.hpp"
#include <list>

class ListContainer : public Container
{
    protected:
        list<Base*> baseList;
        Base* child;
    public:
        ListContainer(): child(nullptr) {}
        ListContainer(Sort* temp): child(nullptr)
	{
	    sort_function = temp;
	} 
	void add_element(Base* element)
	{
	    baseList.push_back(element);
	}
	void print()
	{
	    list<Base*>::iterator it;
	       for(it = baseList.begin(); it != baseList.end(); it++) 
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
	      for(it = baseList.begin(); it != baseList.end(); it++) 
	         {
		     if(counter == i)
		        {
			   temp1 = *it;
			}
		     else if(counter == j)
			{
			   temp2 = *it;
			}
		      counter++;
		      counter2++;
		  }
	   counter = 0;
	   counter2 = 0;
	       for(it = baseList.begin(); it != baseList.end(); it++) 
		  {
		      if(counter == i)
			{
			    *it = temp2;
			}
		      else if(counter == j)
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
	         for(it = baseList.begin(); it != baseList.end(); it++) 
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
			return baseList.size();
            }
};
