#include"pntvec.h"
#include<iostream>
#include<sstream>

int main()
{//tests are in their own scope to re-use memory and variable names
    
    {
        pntvec p;
        if(p.get_x() !=0.0 | p.get_y() !=0.0 | p.get_z() != 0.0)
        {
            std::cout<<"Error in pntvec::pntvec()."<<std::endl;
            return -1;
            //throw;
        }
    }
    
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
        pntvec d(-1.0,-1.0,-1.0);
        pntvec e = a + d;
        pntvec f(0.4,0.4,0.4);
        pntvec g = f + e;
        if(a.get_x() != 1.0 | a.get_y() != 2.0 | a.get_z() != 3.0)
        {
            if(e.get_x() != 0.0 | e.get_y() != 1.0 | e.get_z() != 2.0)
            {
                if(g.get_x() != 0.4 | g.get_y() != 1.4 | g.get_z() != 2.4)
                {
                    std::cout<<"Error in pntvec::operator+ (const pntvec & rhs)."<<std::endl;            
                    return -1;

                }
            }
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
        pntvec d(-1.0,-1.0,-1.0);
        pntvec e = a - d;
        if(e.get_x() != 1.0 | e.get_y() != 1.0 | e.get_z() != 1.0)
        {
            std::cout<<"Error in pntvec::operator- (const pntvec & rhs)."<<std::endl;
            return -1;
        }
        pntvec f(0.5,0.5,0.5);
        pntvec g(0.4,0.4,0.4);
        pntvec h = f - g;
        if(h.get_x() != 0.1 | h.get_y() != 0.1 | h.get_z() != 0.1)
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
        double half = 0.5;
        pntvec c = a * half;
        if(a.get_x() != 3.0 | a.get_y() != 3.0 | a.get_z() != 3.0)
        {
            if(c.get_x() != 1.5 | c.get_y() != 1.5 | c.get_z() != 1.5)
            {
                // std::cout<<a.get_x()<<std::endl;
                // std::cout<<a.get_y()<<std::endl;
                // std::cout<<a.get_z()<<std::endl;
                std::cout<<"Error in pntvec::operator* (const double & rhs)."<<std::endl;
                return -1;

            }
        }
    }
    //Tests a = -b
    {
        //delete(&b);
        pntvec b(1.0,2.0,3.0);
        //delete(&c);        
        pntvec a = -b;
        pntvec c(0.3,0.3,0.3);
        pntvec d = -c;
        if(a.get_x() != -1.0 | a.get_y() != -2.0 | a.get_z() != -3.0)
        {
            if(d.get_x() != -0.3 | d.get_y() != -0.3 | d.get_z() != -0.3)
            {
                // std::cout<<a.get_x()<<std::endl;
                // std::cout<<a.get_y()<<std::endl;
                // std::cout<<a.get_z()<<std::endl;
                std::cout<<"Error in pntvec::operator- ()."<<std::endl;
                return -1;

            }
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
        std::stringstream float_pnt_in("-0.2 1.5 0.4");
        pntvec b;
        float_pnt_in >> b;
        if(a.get_x() != 1.0 | a.get_y() != 2.0 | a.get_z() != 3.0)
        {
            if(b.get_x() != -0.2 | b.get_y() != 1.5 | b.get_z() != 0.4)
            {
                std::cout<<"Error in operator>> (std::istream & in, pntvec & p)."<<std::endl;            
                return -1;

            }
        }

    }
    //If all tests pass, returns no error
    std::cout<<"No error."<<std::endl;
    return 0;
}