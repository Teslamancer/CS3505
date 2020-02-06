/*
 * This is a tester that I wrote last year.  It reads
 * words from a text file, then adds the words to two sets: A built-in
 * set class, and our hashset class.  After reading the file, it
 * prints out all the words stored in the STL set object.  At the end
 * of the test, it prints out the sizes of both sets to see that they
 * are the same.
 *
 *
 * If the comments wrap lines, widen your emacs window.
 *
 * Peter Jensen
 * January 29, 2019
 */

#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include "hashset.h"
#include "node.h"

// For convenience only:

using namespace std;

// Note:  Our classes were declared in a cs3505 namepsace.
//        Instead of 'using namespace cs3505', I qualified the class names 
//        below with cs3505::
//        I did this for clarity.

int main ()
{
  // Open up another block.  This way, when the block ends,
  // variables local to the block will be destroyed, but main
  // will still be running.  (Did you know that you can open
  // up a block at any time to control local variable scope and
  // lifetime?)
  
  {
    // Create the two sets.  Declaring the local variables constructs the objects.
  
    set<string>         stl_set;  // The built-in set class - no constructor parameters.

    cs3505::hashset     our_set(1000);  // Our set class, with a hashtable of 1000 slots.
  
    // Open the file stream for reading.  (We'll be able to use it just like
    //   the keyboard stream 'cin'.)

    ifstream in("Yankee.txt");

    // Loop for reading the file.  Note that it is controlled
    //   from within the loop (see the 'break').
    
    while (true)
    {
      // Read a word (don't worry about punctuation)
      
      string word;
      in >> word;

      // If the read failed, we're probably at end of file
      //   (or else the disk went bad).  Exit the loop.
      
      if (in.fail())
	break;

      // Word successfully read.  Add it to both sets.
      
      stl_set.insert(word);
      our_set.add(word);
    }

    // Close the file.

    in.close();

    // Print out all the words in the reference solution.

    for (set<string>::iterator it = stl_set.begin(); it != stl_set.end(); it++)
    {
      string word = *it;
      cout << word << endl;
    }

    // Print out the number of words found in each set.

    cout << "STL set contains " << stl_set.size() << " unique words.\n";
    cout << "Our set contains " << our_set.get_size() << " unique words.\n"; 
    
    // Done.  Notice that this code block ends below.  Any local
    // variables declared within this block will be automatically
    // destroyed.  Local objects will have their destructors
    // called.  (Blocks are great for controlling scope/lifetime.)
  }

  // I really should test here to make sure that memory got cleaned up (that the
  // nodes and tables were deleted appropriately).  There is no such test here.
  // It's simple to construct a test that counts objects:
  //   Add a public static int variable to each class declaration
  //   Add corresponding static int definitions to the .cpp file, set the variable to 0
  //   An each constructor, increment once
  //   An each destructor, decrement once
  //   Check counts here to make sure every created object has been destroyed.
  
  return 0;
}


/** Computes a table index for a given string.
    *   If two strings have the same contents, their
    *   hash code (table index) will be identical.
    * The hash code is guaranteed to be in the
    *   range [0..capacity).
    */  
	/*
  int hashset::hash (const std::string & s) const
  {
    // A well-known hash algorithm.  Do not change!!!

    long long hash = 0;
    for (int i = 0; i < s.length(); i++)
      hash = ((hash*2237) + s[i]) % capacity;

    return static_cast<int>(hash);
  }
*/
