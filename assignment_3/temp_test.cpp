#include<iostream>
#include<string>
#include"string_set.h"

// For convenience only:

using namespace std;

// Note:  Our classes were declared in a cs3505 namepsace.
//        Instead of 'using namespace cs3505', I qualified the class names 
//        below with cs3505::
//        I did this for clarity.

int main ()
{
    cs3505::string_set set();
    set.add("a");
    set.add("c");
    set.add("b");
    set.debug_output();

  return 0;
}

