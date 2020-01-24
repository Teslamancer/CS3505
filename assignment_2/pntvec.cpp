#include<iostream>
#include<cmath>
#include"pntvec.h"



pntvec::pntvec (const double & x_in, const double & y_in, const double & z_in)
    :x(x_in), y(y_in), z(z_in)
{    
}
pntvec::pntvec (const pntvec & other)//copy constructor
    :x(other.x), y(other.y), z(other.z)
{
}
pntvec::pntvec ()//default constructor
    :x(0.0), y(0.0), z(0.0)
{
} 

const pntvec pntvec::operator+ (const pntvec & rhs) const//for addition
{
    double result_x=0.0;
    double result_y=0.0;
    double result_z=0.0;
    result_x = this->x + rhs.x; //std::cout<<result_x<<std::endl;
    result_y = this->y + rhs.y;//std::cout<<result_y<<std::endl;
    result_z = this->z + rhs.z;//std::cout<<result_z<<std::endl;
    pntvec result(result_x,result_y,result_z);
    return result;
}
const pntvec pntvec::operator- (const pntvec & rhs) const//for subtraction
{
    double result_x=0.0;
    double result_y=0.0;
    double result_z=0.0;
    result_x = this->x - rhs.x;
    result_y = this->y - rhs.y;
    result_x = this->y - rhs.y;
    pntvec result(result_x,result_y,result_z);
    return result;
}
const pntvec pntvec::operator- ()//for negation
{
    pntvec result(*this);
    return result * -1.0;
}
const pntvec pntvec::operator* (const double & rhs)//for scaling
{
    double result_x=0.0;
    double result_y=0.0;
    double result_z=0.0;
    result_x = this->x * rhs;
    result_y = this->y * rhs;
    result_z = this->z * rhs;
    pntvec result(result_x,result_y,result_z);
    return result;
}
const pntvec & pntvec::operator= (const pntvec & rhs)//for assignment
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}

std::ostream & operator<< (std::ostream & out, const pntvec & p)//for outputting to output stream
{
    out<<"(";
    out<<p.x;
    out<<", ";
    out<<p.y;
    out<<", ";
    out<<p.z;
    out<<")";
    return out;
}
std::istream & operator>> (std::istream & in, pntvec & p) //for inputting to a pntvec
{
    in>>p.x>>p.y>>p.z;
    return in;
}

double pntvec::distance_to(const pntvec & other) const
{
    return std::sqrt((other.x-this->x)*(other.x-this->x)+(other.y-this->y)*(other.y-this->y)+(other.z-this->z)*(other.z-this->z));
}

double pntvec::get_x() const
{
    return this->x;
}
double pntvec::get_y() const
{
    return this->y;
}
double pntvec::get_z() const
{
    return this->z;
}
