/* A 'string set' is defined as a set of strings stored
 * in sorted order in a drop list.  See the class video
 * for details.
 *
 * For lists that do not exceed 2^(max_next_width elements+1)
 * elements, the add, remove, and contains functions are 
 * O(lg size) on average.  The operator= and get_elements 
 * functions are O(size).   
 * 
 * Peter Jensen
 * January 28, 2020
 */

#include "string_set.h"
#include <iostream>  // For debugging, if needed.

namespace cs3505
{
  /*******************************************************
   * string_set member function definitions
   ***************************************************** */
  
  /** Constructor:  The parameter indicates the maximum
    *   width of the next pointers in the drop list nodes.
    */
  string_set::string_set(int max_next_width)
    :max_next_width(max_next_width),head(new node), size(0)
  {
    for(int i=0;i<max_next_width;i++)
    {
        head->droplist.push_back(NULL);
    }
  }

  
  /** Copy constructor:  Initialize this set
    *   to contain exactly the same elements as
    *   another set.
    */
  string_set::string_set (const string_set & other)
    :max_next_width(other.max_next_width), size(other.size), head(new node())
  {
	  
	  for (int i = 0; i < max_next_width; i++)
	  {
		  this->head->droplist.push_back(NULL);
	  }
    node* current = other.head->droplist[0];
    while(current != NULL)
    {
      this->add(current->data);
      current = current->droplist[0];
    }
  }


  /** Destructor:  release any memory allocated
    *   for this object.
    */
  string_set::~string_set()
  {
	  /*node* current = head;
	  node* next = head;
    while(current != NULL)
    {
      next = current->droplist[0];
      delete (*current);
      current = next;
    }*/
  }

  /**
   * adds the string element to the set in sorted order
   */
  void string_set::add(const std::string & target)
  {
    std::vector<node*> previous(this->max_next_width);
    node * current = this->head;
    for(int i=this->max_next_width-1;i>=0;i--)
    {
		if (i == 0) 
		{
			while (current->droplist[0] != NULL && current->droplist[0]->data < (target))
			{
				previous[0] = current;
				current = current->droplist[0];
			}
			int nodeSize = 1;
			while (rand() % 2 == 0)
				nodeSize++;
			node targetNode = new node(*target);
			for (int x = 0; x < nodeSize;x++) 
			{

			}
		}
		
		if (current->droplist[i] == NULL || current->droplist[i]->data > target)
		{
			previous[i] = current;
		}
		else
		{
			current = current->droplist[i];
			i++;
		}
    }

  }
  /**
    * Prints each node with the values stored in its pointers
    */
  void string_set::debug_output() const
  {
      node * current = head;
      std::cout<<"DATA"<<'\t'<<std::endl;
      while(current != NULL)
      {
        std::cout<<current->data<<'\t';
        for(int i=0;i<this->max_next_width;i++)
        {
          std::cout<<current->droplist[i]->data<<'\t';
        }
        std::cout<<std::endl;
      }
  }
  // Additional public and private helper function definitions needed

}
