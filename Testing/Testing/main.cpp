#include <cstdio>
#include <string>
class status {
    std::string value;
public:
    void set(std::string);
    status(std::string);
};

void status::set(std::string s) {
    value = s;
}
status::status(std::string s) {
    value = s;
}
class remote {
private:
    status _status;
public:
    
    remote(std::string);
};

remote::remote(std::string s) 
    :_status(s)
{

}

class observable {
private:
    status _status;
public:
    
    observable(std::string);
};

observable::observable(std::string s)
    :_status(s)
{

}

class user_status: public status, public remote, public observable {
private:
    
public:
    //status status_struct;
    //status _status;
    user_status(std::string);
};

user_status::user_status(std::string s)
    :status(s),remote(s), observable(s)
{

}

int main()
{
    user_status* u_status = new user_status("test1");
    remote* r_status = u_status;
    observable* o_status = u_status;
    status* _status = u_status;
}