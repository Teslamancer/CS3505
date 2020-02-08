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
        :max_next_width(max_next_width), head(new node), size(0)
    {
        for (int i = 0; i < max_next_width; i++)
        {
            head->droplist.push_back(NULL);
        }
    }


    /** Copy constructor:  Initialize this set
      *   to contain exactly the same elements as
      *   another set.
      */
    string_set::string_set(const string_set& other)
        :max_next_width(other.max_next_width), size(other.size), head(new node())
    {

        for (int i = 0; i < max_next_width; i++)
        {
            this->head->droplist.push_back(NULL);
        }
        node* current = other.head->droplist[0];
        while (current != NULL)
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
    void string_set::add(const std::string& target)
    {
        std::vector<node*> previous(this->max_next_width);
        node* current = this->head;
        for (int i = this->max_next_width - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                previous[0] = current;
                while (current->droplist[0] != NULL && current->droplist[0]->data < (target))
                {
                    current = current->droplist[0];
                    previous[0] = current;
                }
                int nodeSize = 1;
                while (rand() % 2 == 0 && nodeSize <= max_next_width)
                    nodeSize++;
                node* targetNode = new node(target);
                targetNode->droplist.resize(nodeSize);
                for (int x = nodeSize - 1; x >= 0; x--)
                {
                    node* temp = previous[x]->droplist[x];
                    targetNode->droplist[x] = temp;
                    previous[x]->droplist[x] = targetNode;
                }
                break;
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
    const std::vector<node*> string_set::generate_previous(const std::string& target) const
    {

    }
    /**
      * Prints each node with the values stored in its pointers
      */
    void string_set::debug_output() const
    {
        node* current = head;
        std::cout << "DATA" << '\t' <<"POINTS TO"<<std::endl;
        while (current != NULL)
        {
            std::cout << current->data << '\t';
            for (int i = 0; i < current->droplist.size(); i++)
            {
                if(current->droplist[i] != NULL)
                    std::cout << current->droplist[i]->data << '\t';
            }
            std::cout << std::endl;
            current = current->droplist[0];
        }
    }
    // Additional public and private helper function definitions needed

}
