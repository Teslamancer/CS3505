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
        :max_next_width(other.max_next_width), size(0), head(new node())
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

    /*const int string_set::new_count() const
    {
        return node::newCount;
    }

    const int string_set::del_count() const
    {
        return node::delCount;
    }*/
    /** Destructor:  release any memory allocated
      *   for this object.
      */
    string_set::~string_set()
    {
        node* current = head;
        node* next = head;
      while(current != NULL)
      {
        //if(current->droplist[0] != NULL)
        next = current->droplist[0];
        delete (current);
        current = next;
      }
    }
    /*
        This returns a vector of all the elements of the set in order
    */
    std::vector<std::string> string_set::get_elements()
    {
        std::vector<std::string> toReturn;
        node* current = this->head->droplist[0];
        while (current != NULL)
        {
            toReturn.push_back(current->data);
            current = current->droplist[0];
        }
        return toReturn;
    }
    /*
        Returns size of set as an int
    */
    int  string_set::get_size() const
    {
        return this->size;
    }
    /**
     * adds the string element to the set in sorted order
     */
    void string_set::add(const std::string& target)
    {
        int nodeSize = 1;
        std::vector<node*> previous = generate_previous(target);
        if (previous[0]->droplist[0] != NULL && previous[0]->droplist[0]->data == target)
            return;
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
        this->size++;
    }

    /*
        returns a bool indicating whether or not the target string exists in the set
    */
    bool string_set::contains(const std::string& target) const
    {
        std::vector<node*> previous = generate_previous(target);
        if (previous[0]->droplist[0] != NULL && previous[0]->droplist[0]->data == target)
            return true;
        else
            return false;
    }
    /*
        copies the elements of the rhs side to the lhs set
    */
    string_set& string_set::operator= (const string_set& rhs)
    {
        string_set toReturn(rhs);
        return toReturn;
    }
    /*
        This removes the target element from the set if it exists
    */
    void string_set::remove(const std::string& target)
    {
        std::vector<node*> previous = generate_previous(target);
        if (previous[0]->droplist[0] == NULL || previous[0]->droplist[0]->data != target)
            return;
        else
        {
            node* toRemove = previous[0]->droplist[0];
            for (int i = toRemove->droplist.size() - 1; i >= 0; i--)
            {
                previous[i]->droplist[i] = toRemove->droplist[i];
            }
            delete(toRemove);
        }

    }
    /*
        This helper function generates a previous vector in order to find the insertion or deletion point of a target string.
    */
    const std::vector<node*> string_set::generate_previous(const std::string& target) const
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
                return previous;
            }

            if (current->droplist[i] == NULL || current->droplist[i]->data >= target)
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
    /*void string_set::debug_output() const
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
    }*/
    // Additional public and private helper function definitions needed

}
