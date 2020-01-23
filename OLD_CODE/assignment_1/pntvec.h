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

typedef struct {

  double x;
  double y;
  double z;

} pntvec;
