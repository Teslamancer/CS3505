#include<iostream>
#include"pntvec.h"



pntvec::pntvec (double x_in, double y_in, double z_in)
    :x(x_in), y(y_in), z(z_in)
{    
}
pntvec::pntvec (const pntvec & other)//copy constructor
    :x(other.x), y(other.y), z(other.z)
{
}
pntvec::pntvec ()//default constructor
    :x(11.0), y(0.0), z(0.0)
{
} 

const pntvec pntvec::operator+ (const pntvec & rhs) const//for addition
{
    double result_x=0.0;
    double result_y=0.0;
    double result_z=0.0;
    result_x = this->x + rhs.x;
    result_y = this->y + rhs.y;
    result_x = this->y + rhs.y;
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
const pntvec pntvec::operator- () const//for negation
{
    pntvec result(*this);
    return result * -1.0;
}
const pntvec pntvec::operator* (const double rhs)//for scaling
{
    double result_x=0.0;
    double result_y=0.0;
    double result_z=0.0;
    result_x = this->x * rhs;
    result_y = this->y * rhs;
    result_x = this->y * rhs;
    pntvec result(result_x,result_y,result_z);
    return result;
}
pntvec & pntvec::operator= (const pntvec & rhs)//for assignment
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}

std::ostream & operator<< (std::ostream & out, const pntvec & p)//for outputting to output stream
{
    out<<"("<<p.x<<", "<<p.y<<", "<<p.z<<")";
    return out;
}
std::istream & operator>> (std::istream & in, pntvec & p) //for inputting to a pntvec
{
    in>>p.x>>p.y>>p.z;
    return in;
}

const double pntvec::get_x() const
{
    return this->x;
}
const double pntvec::get_y() const
{
    return this->y;
}
const double pntvec::get_z() const
{
    return this->z;
}
