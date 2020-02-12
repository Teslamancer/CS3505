#include<iostream>
#include<string>
#include"string_set.h"
#include<stdlib.h>
// For convenience only:

using namespace std;

// Note:  Our classes were declared in a cs3505 namepsace.
//        Instead of 'using namespace cs3505', I qualified the class names 
//        below with cs3505::
//        I did this for clarity.

int main()
{
    {
        cs3505::string_set set(100000);
        set = set;
        for (int i = 0; i < 10000; i++)
        {
            set.add(""+i);
        }
        //set.debug_output();

        cout << set.contains("a") << endl;
        cout << set.contains("b") << endl;
        cout << set.contains("c") << endl;
        cout << set.contains("d") << endl;

        cout << "Size: "<<set.get_size() << endl;

        cout << "New Count: " << set.new_count() << endl;

        cout << "Delete Count: " << set.del_count() << endl;

        for (int i = 0; i < 100; i++)
        {
            set.add("" + i);
        }

        cout << "Size: " << set.get_size() << endl;

        cout << "New Count: " << set.new_count() << endl;

        cout << "Delete Count: " << set.del_count() << endl;

        for (int i = 0; i < 10000; i+=2)
        {
            set.remove("" + i);
        }

        cout << "Size: " << set.get_size() << endl;

    cout << "New Count: " << set.new_count() << endl;

    cout << "Delete Count: " << set.del_count() << endl;

    for (int i = 0; i < 10000; i += 2)
    {
        set.remove("" + i);
    }

    cout << "Size: " << set.get_size() << endl;

    cout << "New Count: " << set.new_count() << endl;

    cout << "Delete Count: " << set.del_count() << endl;

    cs3505::string_set copy = set;

    cout << "Size: " << copy.get_size() << endl;

    cout << "New Count: " << copy.new_count() << endl;

    cout << "Delete Count: " << copy.del_count() << endl;

}
{
    cs3505::string_set set1(10);

    set1.add("a");
    set1.add("c");
    set1.add("b");
    set1.add("d");
    set1.add("a");

    vector<string> elements = set1.get_elements();
    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements[i] << ',';
    }
    cout << endl << endl;

    cs3505::string_set copy = set1;
    set1.remove("a");
    set1.remove("b");
    set1.remove("d");
    set1.remove("c");

    elements = copy.get_elements();
    for (int i = 0; i < elements.size(); i++)
    {
        cout << elements[i] << ',';
    }
    cout << endl << endl;



    cout << "Total New Count: " << cs3505::string_set::new_count() << endl;
    cout << "Total Delete Count: " << cs3505::string_set::del_count() << endl;



    cs3505::string_set copyset = set1;
    set1.remove("b");
    /*set.add("a");
    set.add("a");
    set.add("a");
    set.add("c");
    set.add("b");*/
    //set.debug_output();
    cout << endl;
    //copyset.debug_output();

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

    cs3505::string_set* heapSet = new cs3505::string_set(100);
    //cout << heapSet->new_count() << endl;
    heapSet->add("a");
    //cout << heapSet->new_count() << endl;
    heapSet->add("b");
    //cout << heapSet->new_count() << endl;
    heapSet->add("c");
    //cout << heapSet->new_count() << endl;
    heapSet->add("a");
    cout << heapSet->new_count() << endl;

    delete(heapSet);
    cout << heapSet->del_count() << endl;
}
//{
//cs3505::string_set newSet(20);
//
//for (int i = 0; i < 10000; i++) {
//    if (i % 2 == 0)
//        newSet.add(to_string(i));
//}
//}
    cout << "Total New Count: " << cs3505::string_set::new_count() << endl;
    cout << "Total Delete Count: " << cs3505::string_set::del_count() << endl;

    return 0;
}

