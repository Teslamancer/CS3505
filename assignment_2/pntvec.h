/* A pntvec is a c-style data structure that represents
 * a 3D point or vector:
 *
 * struct { double x, double y, double z }
 *
 * The 'typedef' gives this structure its type name.  Otherwise,
 * it is just three double values bound together.  You
 * can use fields in this struct exactly like an object:
 * 
 * pntvec p;
 *
 * p.x = 5;
 * p.y = p.x + 2;
 *
 * etc.
 *
 * Note:  Students are not allowed to edit this .h file.
 * During testing I will replace this .h file with a pntvec
 * class that has more features, but that is otherwise
 * compatible. 
 *
 * Also, do not compile this file directly.  If you do so, you'll
 * end up with a precompiled header file in your directory.
 * Precompiled headers will cause trouble in future assignments
 * because your edits won't seem to have any effect.  Precompiled
 * files have this form:
 *
 *    file.gch
 *
 * You can remove these .gch files safely:  rm file.gch
 *
 * Peter Jensen
 * January 4, 2020
 */


#ifndef PNTVEC_H
#define PNTVEC_H
#include<iostream>
class pntvec
{
  private:
    double x, y, z;
  public:
    pntvec (const double & x, const double & y, const double & z);
    pntvec (const pntvec & other);//copy constructor
    pntvec (); //default constructor

    const pntvec operator+ (const pntvec & rhs) const;//for addition
    const pntvec operator- (const pntvec & rhs) const;//for subtraction
    const pntvec operator- ();//for negation
    const pntvec operator* (const double & rhs);//for scaling
    const pntvec & operator= (const pntvec & rhs);//for assignment

    friend std::ostream & operator<< (std::ostream & out, const pntvec & p);//for outputting to output stream
    friend std::istream & operator>> (std::istream & in, pntvec & p); //for inputting to a pntvec

    double get_x() const;
    double get_y() const;
    double get_z() const;
};
#endif
