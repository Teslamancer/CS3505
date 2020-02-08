/* This node class is used to build linked lists for the
 * string_set class.
 *
 * Peter Jensen
 * January 28, 2020
 */

#include "node.h"

// We're not in a namespace.  We are not in any class.  Symbols defined
//   here are globally available.  We need to qualify our function names
//   so that we are definining our cs3505::node class functions.
//
// Note that we could also use the namespace cs3505 { } block.  This would
//   eliminate one level of name qualification.  The 'using' statement will
//   not help in this situation.  
// 
// Qualify it as shown here for functions: cs3505::node::functionname, etc.

/*******************************************************
 * node member function definitions
 ***************************************************** */

// Students will decide how to implement the constructor, destructor, and
//   any helper methods.
cs3505::node::node(std::string s)
    :data(s)
{
}

cs3505::node::node(const node & other)
    :data(other.data), droplist(other.droplist)
{

}

cs3505::node::node()
    :data("")
{

}

cs3505::node::~node()
{
	for (int i = 0; i < this->droplist.capacity(); i++) 
	{
		this->droplist[i] = NULL;
	}
}

const std::string cs3505::node::get_data() const
{
    return this->data;
}

