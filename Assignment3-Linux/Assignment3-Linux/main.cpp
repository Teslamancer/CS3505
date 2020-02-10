#include<iostream>
#include<string>
#include"string_set.h"

// For convenience only:

using namespace std;

// Note:  Our classes were declared in a cs3505 namepsace.
//        Instead of 'using namespace cs3505', I qualified the class names 
//        below with cs3505::
//        I did this for clarity.

int main()
{
    cs3505::string_set set(10);
    set.add("a");
    set.add("a");
    set.add("a");
    set.add("c");
    set.add("b");
    set.debug_output();

    cout << set.contains("a") << endl;
    cout << set.contains("b") << endl;
    cout << set.contains("c") << endl;
    cout << set.contains("d") << endl;

    cout << set.get_size() << endl;

    vector<string> elements = set.get_elements();
    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements[i] << ',';
    }
    cout << endl<<endl;

    cs3505::string_set copyset = set;
    set.remove("b");
    /*set.add("a");
    set.add("a");
    set.add("a");
    set.add("c");
    set.add("b");*/
    set.debug_output();
    cout << endl;
    copyset.debug_output();

    cout << copyset.contains("a") << endl;
    cout << copyset.contains("b") << endl;
    cout << copyset.contains("c") << endl;
    cout << copyset.contains("d") << endl;

    cout << copyset.get_size() << endl;

    vector<string> copyelements = copyset.get_elements();
    for (int i = 0; i < copyelements.size(); i++)
    {
        cout << copyelements[i] << ',';
    }
    cout << endl;

    //cs3505::string_set* heapSet = new cs3505::string_set(100);
    ////cout << heapSet->new_count() << endl;
    //heapSet->add("a");
    ////cout << heapSet->new_count() << endl;
    //heapSet->add("b");
    ////cout << heapSet->new_count() << endl;
    //heapSet->add("c");
    ////cout << heapSet->new_count() << endl;
    //heapSet->add("a");
    //cout << heapSet->new_count()<<endl;

    //delete(heapSet);
    //cout << heapSet->del_count() << endl;


    return 0;
}

