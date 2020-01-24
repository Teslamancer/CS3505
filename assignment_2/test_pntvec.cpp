#include"pntvec.h"
#include<iostream>
#include<sstream>

int main()
{//tests
    //Tests pntvec a()
    // try
    // {
    {
        pntvec p;
        if(p.get_x() !=0.0 | p.get_y() !=0.0 | p.get_z() != 0.0)
        {
            std::cout<<"Error in pntvec::pntvec()."<<std::endl;
            return -1;
            //throw;
        }
    }
    //}
    // catch(...)
    // {
    //     std::cout<<"Error in pntvec()."<<std::endl;
    //     return -1;
    // }
    //Tests pntvec a(1.0,2.0,3.0)
    {
        pntvec p(1.0,2.0,3.0);
        if(p.get_x() != 1.0 | p.get_y() !=2.0 | p.get_z() != 3.0)
        {
            std::cout<<"Error in pntvec::pntvec(double, double, double)."<<std::endl;
            return -1;
        }

    }
    //Tests pntvec a(b)
    {
        pntvec p(1.0,2.0,3.0);
        pntvec t(p);
        if(t.get_x() !=1.0 | t.get_y() !=2.0 | t.get_z() != 3.0)
        {
            std::cout<<"Error in pntvec::pntvec(pntvec const & other)."<<std::endl;
            return -1;
        }

    }
    
    //Tests a = b
    {
        pntvec p(1.0,2.0,3.0);
        pntvec temp;
        temp = p;
        if(temp.get_x() !=1.0 | temp.get_y() !=2.0 | temp.get_z() != 3.0)
        {
            std::cout<<"Error in pntvec::operator= (const pntvec & rhs)."<<std::endl;
            return -1;
        }

    }

    //Tests a = b + c
    {
        pntvec b;
        pntvec c(1.0, 2.0, 3.0);
        pntvec a = b + c;
        if(a.get_x() != 1.0 | a.get_y() != 2.0 | a.get_z() != 3.0)
        {
            std::cout<<"Error in pntvec::operator+ (const pntvec & rhs)."<<std::endl;            
            return -1;
        }

    }

    //Tests a = b - c
    {
        //delete(&b);
        pntvec b(1.0,2.0,3.0);
        //delete(&c);
        pntvec c(1.0,2.0,3.0);
        pntvec a = b - c;
        if(a.get_x() != 0.0 | a.get_y() != 0.0 | a.get_z() != 0.0)
        {
            std::cout<<"Error in pntvec::operator- (const pntvec & rhs)."<<std::endl;
            return -1;
        }

    }
    //Tests a = b * d
    {
        //delete(&b);
        pntvec b(1.0,1.0,1.0);
        //delete(&c);
        double d = 3.0;
        pntvec a = b * d;
        if(a.get_x() != 3.0 | a.get_y() != 3.0 | a.get_z() != 3.0)
        {
            // std::cout<<a.get_x()<<std::endl;
            // std::cout<<a.get_y()<<std::endl;
            // std::cout<<a.get_z()<<std::endl;
            std::cout<<"Error in pntvec::operator* (const double & rhs)."<<std::endl;
            return -1;
        }
    }
    //Tests a = -b
    {
        //delete(&b);
        pntvec b(1.0,1.0,1.0);
        //delete(&c);        
        pntvec a = -b;
        if(a.get_x() != -1.0 | a.get_y() != -1.0 | a.get_z() != -1.0)
        {
            // std::cout<<a.get_x()<<std::endl;
            // std::cout<<a.get_y()<<std::endl;
            // std::cout<<a.get_z()<<std::endl;
            std::cout<<"Error in pntvec::operator- ()."<<std::endl;
            return -1;
        }
    }
    //Tests d = a.distance_to(b);
    {
        pntvec a(1.0,1.0,1.0);
        pntvec b(a);
        if(a.distance_to(b)!=0.0)
        {
            std::cout<<"Error in pntvec::distance_to(const pntvec & other)."<<std::endl;
            return -1;
        }
    }
    //Tests out << a;
    {
        pntvec p;
        std::stringstream pnt("");
        pnt<<p;

        if(pnt.str() !="(0, 0, 0)")
        {
            std::cout<<"Error in operator<< (std::ostream & out, const pntvec & p)."<<std::endl;
            return -1;
        }
    }
    //Tests in >> a;
    {
        pntvec a;
        std::stringstream pnt_in("1.0 2.0 3.0");
        pnt_in >> a;
        if(a.get_x() != 1.0 | a.get_y() != 2.0 | a.get_z() != 3.0)
        {
            std::cout<<"Error in operator>> (std::istream & in, pntvec & p)."<<std::endl;            
            return -1;
        }

    }
    std::cout<<"No error."<<std::endl;
    return 0;
}