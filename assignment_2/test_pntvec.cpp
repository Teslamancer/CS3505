#include"pntvec.h"
#include<iostream>

int main()
{
    //Tests pntvec a()
    try
    {
        pntvec p;
        if(p.get_x() !=0.0 | p.get_y() !=0.0 | p.get_z() != 0.0)
        {
            throw;
        }
    }
    catch(...)
    {
        std::cout<<"Error in pntvec()."<<std::endl;
        return -1;
    }
    //Tests pntvec a(1.0,2.0,3.0)
    // pntvec p(1.0,2.0,3.0);
    // if(p.get_x() != 1.0 | p.get_y() !=2.0 | p.get_z() != 3.0)
    // {
    //     std::cout<<"Error in pntvec(double, double, double)."<<std::endl;
    //     return -1;
    // }
    // //Tests pntvec a(b)
    // pntvec t(p);
    // if(t.get_x() !=1.0 | t.get_y() !=2.0 | t.get_z() != 3.0)
    // {
    //     std::cout<<"Error in pntvec(pntvec const & other)."<<std::endl;
    //     return -1;
    // }
    
    // //Tests a = b
    // pntvec temp;
    // temp = p;
    // if(temp.get_x() !=1.0 | temp.get_y() !=2.0 | temp.get_z() != 3.0)
    // {
    //     std::cout<<"Error in operator= (const pntvec & rhs)."<<std::endl;
    //     return -1;
    // }

    // //Tests a = b + c
    // pntvec b;
    // pntvec c(1.0, 2.0, 3.0);
    // pntvec a = b + c;
    // if(a.get_x() != 1.0 | a.get_y() != 2.0 | a.get_z() != 3.0)
    // {
    //     std::cout<<"Error in operator+ (const pntvec & rhs)."<<std::endl;
    //     return -1;
    // }

    // //Tests a = b - c
    // delete(&b);
    // pntvec b(1.0,2.0,3.0);
    // delete(&c);
    // pntvec c(1.0,2.0,3.0);
    // a = b - c;
    // if(a.get_x() != 0.0 | a.get_y() != 0.0 | a.get_z() != 0.0)
    // {
    //     std::cout<<"Error in operator- (const pntvec & rhs)."<<std::endl;
    //     return -1;
    // }
    //TODO: Tests a = b * d

    //TODO: Tests a = -b

    //TODO: Tests d = a.distance_to(b);

    //TODO: Tests out << a;

    //TODO: Tests in >> a;
    std::cout<<"No error."<<std::endl;
    return 0;
}