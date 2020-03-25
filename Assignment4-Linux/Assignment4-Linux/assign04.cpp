/*
 * Assignment 04 -- An exploration of polymorphism in multiple
 * inheritance.  This code is instrumented to allow the user to see
 * function calls as they happen.
 *
 * Students need to supply the missing class declarations, constructors,
 * and destructors, as well as any missing or otherwise required functions.
 * When you're done, the output should match the sample output --exactly--.
 *
 * Find the TODO: comments, and replace them with the relevant code.
 *
 * Note that while this code is motivated by a particular problem,
 * much of the functionality is missing.  Students should not try to
 * implement observer functionality or remote connections.
 *
 * Additionally, while you can make multiple inheritance compile, its much
 * tougher to make it work properly.  Students should not fix the
 * deficient design here.  Get the code to compile and match the given
 * design.  Later, you will describe possible fixes in essay questions.
 *
 * Peter Jensen  // TODO -- change this or lose a point.
 * February 28, 2020
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class observer;  // Forward declare this class, we won't make/use it.

/*******************
 * My status class *
 *******************/

 // TODO:  Declare the status class and define the constructor and destructor.
 //   (The body of the constructor and destructor will just have two
 //   statements each for printing out that they are starting / ending
 //   execution.  Use the same indentation and style as shown in the 
 //   example output and the set and get functions below.)
 //
 // Do NOT use a .h file.  Just put the declaration of the class above
 //   the definitions (right here).  In other words, keep it simple.
class status {
    private: 
        string s;
    public:
        status(string s);
        virtual ~status();
        virtual void set(string s);
        virtual string get();
};

status::status(string s)
{
    std::cout << "      ==> status::status" << endl;
    this->s = s;
    std::cout << "      <-- status::status" << endl;
}

status::~status()
{
    std::cout << "      ==> status::~status" << endl;
    //this->s = nullptr;
    std::cout << "      <-- status::~status" << endl;
}

void status::set(string s)
{
    std::cout << "      ==> status::set" << endl;
    this->s = s;
    std::cout << "      <-- status::set" << endl;
}


string status::get()
{
    std::cout << "      ==> status::get" << endl;
    std::cout << "      <-- status::get" << endl;
    return s;
}


/****************************
 * My remote status class *
 ****************************/

 // TODO:  Declare the remote class and define the constructor and destructor.
 //   (The body of the constructor and destructor will just have two
 //   statements each for printing out that they are starting / ending
 //   execution.  Use the same indentation and style as shown in the 
 //   example output and the set and get functions below.)
 //
 // Do NOT use a .h file.  Just put the declaration of the class above
 //   the definitions (right here).  In other words, keep it simple.
class remote :virtual public status{
    private:
        bool has_remote_changed();
        void set_remote_status(string s);
        string get_remote_status();

    public:
        remote(string s);
        ~remote();
        void set(string st);
        string get();
};

remote::remote(string s) 
    :status(s)
{
    std::cout << "    ==> remote::remote" << endl;
    std::cout << "    <-- remote::remote" << endl;
}

remote::~remote() {
    std::cout << "    ==> remote::~remote" << endl;
    std::cout << "    <-- remote::~remote" << endl;
}

void remote::set(string st)
{
    std::cout << "    ==> remote::set" << endl;

    // Update the remote status and also keep it (as a status).

    this->set_remote_status(st);
    status::set(st);              // Change superclass field

    std::cout << "    <-- remote::set" << endl;
}


string remote::get()
{
    std::cout << "    ==> remote::get" << endl;

    // If the remote status has changed, we'll update this
    // object to its remote status before returning it.

    // To avoid resetting the remote status, only set the status
    //   in the superclass.  (Don't use the 'set' function in
    //   this class, or it will set the remote status to what we
    //   just got remotely, which is a waste of time.)

    if (has_remote_changed())
        status::set(this->get_remote_status());

    // Just get the status (from the superclass) and return it.

    string result = status::get();

    std::cout << "    <-- remote::get" << endl;

    return result;
}


bool remote::has_remote_changed()
{
    std::cout << "    ==> remote::has_remote_changed" << endl;
    /* Assume there would be code here to check the remote value. */
    std::cout << "    <-- remote::has_remote_changed" << endl;

    // This function might return true or false at any time (based
    // on some remote status).  For this test, I'll just return
    // false.  (You must assume that true might be returned in
    // the actual, finished program.)

    bool debug_return_value = false;
    return debug_return_value;
}

string remote::get_remote_status()
{
    std::cout << "    ==> remote::get_remote_status" << endl;
    /* Assume a remote status is retrieved. */
    std::cout << "    <-- remote::get_remote_status" << endl;

    return "done";  // Just a stub -- any status might be returned.
}


void remote::set_remote_status(string  status)
{
    std::cout << "    ==> remote::set_remote_status" << endl;
    // Assume the given status is remotely stored/updated. */
    std::cout << "    <-- remote::set_remote_status" << endl;
}


/***********************
 * My observable class *
 ***********************/

 // TODO:  Declare the observable class and define the constructor and destructor.
 //   (The body of the constructor and destructor will just have two
 //   statements each for printing out that they are starting / ending
 //   execution.  Use the same indentation and style as shown in the 
 //   example output and the set and get functions below.)
 //
 // Do NOT use a .h file.  Just put the declaration of the class above
 //   the definitions (right here).  In other words, keep it simple.
class observable : virtual public status{
    private:
        void notify_observers();
    public:
        observable(string s);
        ~observable();
        void register_observer(observer* o);
        void set(string new_status);
};

observable::observable(string s) 
    :status(s)
{
    std::cout << "    ==> observable::observable" << endl;
    std::cout << "    <-- observable::observable" << endl;
}

observable::~observable()
{
    std::cout << "    ==> observable::~observable" << endl;
    std::cout << "    <-- observable::~observable" << endl;
}

void observable::set(string new_status)
{
    std::cout << "    ==> observable::set" << endl;

    // Only change the status and send out notifications 
    //   if the new status is different than the old one.

    if (get() != new_status)  // TODO:  Fix this condition to match the comment above.
    {
        // TODO:  Change superclass field, keep the new value 
        this->status::set(new_status);

        notify_observers();
    }

    std::cout << "    <-- observable::set" << endl;
}


void observable::notify_observers()
{
    std::cout << "    ==> observable::notify_observers" << endl;
    /* Assume observer/delegates are activated. */
    std::cout << "    <-- observable::notify_observers" << endl;
}


void observable::register_observer(observer* o)
{
    std::cout << "    ==> observable::register_observer" << endl;
    /* Assume an observer is added to our list of observers. */
    std::cout << "    <-- observable::register_observer" << endl;
}


/************************
 * My user_status class *
 ************************/

 // TODO:  Declare the user_status class and define the constructor and destructor.
 //   (The body of the constructor and destructor will just have two
 //   statements each for printing out that they are starting / ending
 //   execution.  Indent two spaces.)
 //
 // Do NOT use a .h file.  Just put the declaration of the class above
 //   the definitions (right here).  In other words, keep it simple.
class user_status :public observable, public remote{
    private:
    
    public:
        user_status(string s);
        ~user_status();
        void set(string s);
};


 // TODO:  Additionally, you will need to override a function to make it work.
 //   This is not shown in the class diagram, you are to figure out what
 //   you need (and why).  There will only be a couple of actually useful
 //   statements (and the debugging output statements, indented two spaces).
user_status::user_status(string s)
    :status(s), observable(s), remote(s)
{
    std::cout << "  ==> user_status::user_status" << endl;
    std::cout << "  <-- user_status::user_status" << endl;
}

user_status::~user_status()
{
    std::cout << "  ==> user_status::~user_status" << endl;
    std::cout << "  <-- user_status::~user_status" << endl;
}

void user_status::set(string s) {
    std::cout << "  ==> user_status::set" << endl;
    observable::set(s);
    remote::set(s);
    std::cout << "  <-- user_status::set" << endl;
}

 // TODO:  Nothing else is needed beyond this point.  Do not change main at all.


 /********************
  * My main (tester) *
  ********************/

int main()
{
    // Make one of our objects.

    std::cout << "Creating a user_status object:" << endl;
    std::cout << "------------------------------" << endl;

    user_status* u_status = new user_status("Logged in");

    std::cout << endl;

    // Add our status' pointer to a few vectors.  This
    // will demonstrate polymorphism.

    vector<user_status*> vector_t;
    vector<remote*>      vector_r;
    vector<observable*>  vector_o;
    vector<status*>      vector_s;

    vector_t.push_back(u_status);
    vector_r.push_back(u_status);
    vector_o.push_back(u_status);
    vector_s.push_back(u_status);

    // Use the pointer from each vector.  Set a status,
    //   then get the status.  Because of polymorphism,
    //   this will normally result in the exact same sequence
    //   of function calls.

    string result;

    // First, use a user_status pointer.

    std::cout << "Setting the user status to \"active\" (through a user_status *):" << endl;
    std::cout << "--------------------------------------------------------------" << endl;

    user_status* t = vector_t[0];
    t->set("active");

    std::cout << endl;

    result = t->get();

    std::cout << endl;
    std::cout << "User status is now " << result << "." << endl;
    std::cout << endl;

    // Next, use a remote pointer

    std::cout << "Setting the user status to \"afk\" (through a remote *):" << endl;
    std::cout << "------------------------------------------------------" << endl;

    remote* r = vector_r[0];
    r->set("afk");

    std::cout << endl;

    result = r->get();

    std::cout << endl;
    std::cout << "User status is now " << result << "." << endl;
    std::cout << endl;

    // Next, use an observable pointer

    std::cout << "Setting the user status to \"online\" (through an observable *):" << endl;
    std::cout << "--------------------------------------------------------------" << endl;

    observable* o = vector_o[0];
    o->set("online");

    std::cout << endl;

    result = o->get();

    std::cout << endl;
    std::cout << "User status is now " << result << "." << endl;
    std::cout << endl;

    // Finally, use a status pointer

    std::cout << "Setting the user status to \"ready\" (through a status *):" << endl;
    std::cout << "------------------------------------------------------------" << endl;

    status* s = vector_s[0];
    s->set("ready");

    std::cout << endl;

    result = s->get();

    std::cout << endl;
    std::cout << "User status is now " << result << "." << endl;
    std::cout << endl;

    // Done.  Delete our object (once only).  For fun, delete it
    //   using one of the base class pointers.  (We should still
    //   see all the destructors called.)

    std::cout << "Cleaning up:" << endl;
    std::cout << "------------" << endl;

    delete s;

    std::cout << endl;

    return 0;
}


