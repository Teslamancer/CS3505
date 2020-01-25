#include<iostream>
#include<cmath>
#include"pntvec.h"



pntvec::pntvec (const double & x_in, const double & y_in, const double & z_in)//Parameter constructor
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
//adds two pntvec together
const pntvec pntvec::operator+ (const pntvec & rhs) const
{
    double result_x=0.0;
    double result_y=0.0;
    double result_z=0.0;
    result_x = this->x + rhs.x;
    result_y = this->y + rhs.y;
    result_z = this->z + rhs.z;
    pntvec result(result_x,result_y,result_z);
    return result;
}
//subtracts pntvec rhs from this
const pntvec pntvec::operator- (const pntvec & rhs) const
{
    return pntvec(x-rhs.x,y-rhs.y,z-rhs.z);
}
//negates this pntvec
const pntvec pntvec::operator- ()
{    
    return pntvec(-this->x,-this->y,-this->z);
}
//scales this pntvec by rhs
const pntvec pntvec::operator* (const double & rhs)
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
//assgins this pntvec the same values as rhs
const pntvec & pntvec::operator= (const pntvec & rhs)
{
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}
//outputs this pntvec to ostream
std::ostream & operator<< (std::ostream & out, const pntvec & p)
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
//sets this pntvec's values from istream
std::istream & operator>> (std::istream & in, pntvec & p)
{
    in>>p.x>>p.y>>p.z;
    return in;
}
//calculates distance from this to other pntvec
double pntvec::distance_to(const pntvec & other) const
{
    return std::sqrt((other.x-this->x)*(other.x-this->x)+(other.y-this->y)*(other.y-this->y)+(other.z-this->z)*(other.z-this->z));
}
//returns x-coordinate of this
double pntvec::get_x() const
{
    return this->x;
}
//returns y-coordinate of this
double pntvec::get_y() const
{
    return this->y;
}
//returns z-coordinate of this
double pntvec::get_z() const
{
    return this->z;
}
