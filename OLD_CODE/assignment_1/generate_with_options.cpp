/* This small utility generates test data for assignment #1.  Note that it does
 * not generate solutions -- it only prepares data files for testing student
 * solutions to assignment #1.
 *
 * Command to compile this program (feel free to use a longer executable name):
 *   g++ generate_with_options.cpp -o gwo
 *
 * Caution:  The -o [filename] is how you specify the name of the executable.
 * Put the output file option as the last option on the line.
 * This helps you avoid overwriting your source code with the output file.
 * (Students often mistype this line and overwrite their source code.)
 * 
 * A quiet compilation is a successful compilation.  Any error messages at all 
 * indicate compilation failure.
 * 
 * Example command to run the executable program (after successful complilation):
 *   ./gwo 10 20 12345
 *
 * This program takes three command line arguments:
 *   The first argument is the number of points to create for the cloud file.
 *   The second argument is the scale of the resulting point cloud.
 *   The third argument is the random number generator seed.
 *
 * In the example above, 10 points will be created with each coordinate in
 * the range ([-20..20), [-20..20), [-20..20)), and the point cloud will
 * be the same one every time (as long as the random seed is 12345). 
 *
 * Finally, 'using' statements are expressly forbidden in this assignment.
 *
 * Peter Jensen
 * January 6, 2020
 */


/* Everything in c++ must be declared before it is used.  These declarations
 * are often put into .h files so they can be used in many other programs.
 * Use the 'include' compiler directive to bring those declarations into
 * a program. 
 */

// The c++ iostream library is used when console (or shell) I/O is needed.

#include <iostream>  

// The c++ fstream library is used when file I/O is needed.

#include <fstream> 

// The c++ sstream library is used to treat strings as I/O streams.

#include <sstream>

// The c++ cstdlib library contains a lot of utility functions, including
// functions for generating random numbers.

#include <cstdlib>

// The c++ cmath library contains the sqrt function (not used here).

#include <cmath>

// The vector class works similarly to array lists in other languages.
// Use the 'push_back' function to append items to a vector, then
// access it like an array.  Examples below.

#include <vector>

// I use the same pntvec structure that I expect students to use.  The
// declarations are in a header file (.h file).

#include "pntvec.h"


/* 'using' statements expressly forbidden in this assignment. */

/* I prefer to put my main function at the top of the file.  I also
 * want helper functions.  Since everything must be declared before
 * it is used, the helper functions must be declared before main.
 * These are called forward declarations, and each one is just
 * the complete function header with a semicolon after it.
 */

pntvec generate_point (double scale);

void   output_point   (std::ostream & file, pntvec point);


/* Main -- the application entry point. 
 *
 * Parameters:
 *   argc - a count indicating the number of command line arguments
 *   argv - the command line arguments, as an array of character arrays
 *
 * Return value:
 *    an integer exit code, we return non-zero if an error occured
 */

int main (int argc, char** argv)
{
  // Make sure there are the correct number of command line arguments.

  if (argc != 4)
  {
    std::cout << "Incorrect number of parameters." << std::endl;
    std::cout << "Usage:  " 
              << argv[0] 
              << " [number_of_points] [span_of_points] [random_seed]" 
              << std::endl;

    return 22;  // Indicates invalid argument -- likely ignored by shell.
  }

  // Parse the three arguments.  This is a bit of a pain to do properly.
  // I would like to make sure that the first argument is a positive integer,
  // the second argument a double, and the third argument an unsigned int.
  //
  // To get around this, I'll use streams.  I'll create an input stream
  // that allows me to grab input from a string, and I'll use
  // each argument as that string.
  //
  // To keep it neat, I'll just open new scopes for each conversion. 
  //
  // Fortunately, students will not need any of this in the assignment.

  int point_count;
  double point_scale;
  unsigned int random_seed;  

  // Parse the point count.

  {
    std::stringstream s(argv[1]);  // Create a stream on an argument
    s >> point_count;              // Attempt to convert text
    if (s.fail() || !(point_count>0))
    {
      std::cout << "First argument (point count) must be a positive integer." << std::endl;
      return 22;
    }
  }

  // Parse the scale.

  {
    std::stringstream s(argv[2]);  // Create a stream on an argument
    s >> point_scale;              // Attempt to convert text
    if (s.fail() || !(point_scale > 0))
    {
      std::cout << "Second argument (point cloud scale) must be positive." << std::endl;
      return 22;
    }
  }

  // Parse the random seed.

  {
    std::stringstream s(argv[3]);  // Create a stream on an argument
    s >> random_seed;              // Attempt to convert text
    if (s.fail())
    {
      std::cout << "Third argument must be an integer in [-2^31..2^31)." << std::endl;
      return 22;
    }
  }

  // Seed the random number generator

  std::srand(random_seed);

  // Create the candidate file.  Open the file, 
  //   write out the four random points, close the file.
  //
  // Note:  In c++, declaring an object variable creates
  // the object.  The constructor parameter requires a filename.

  std::ofstream candidate_file("candidates.txt");

  for (int i = 0; i < 4; i++)
  {
    pntvec p = generate_point (point_scale);
    output_point (candidate_file, p);
  }

  candidate_file.close();

  // Create the point cloud and keep it in a vector.

  std::vector<pntvec> point_cloud;  // Creates the list object

  for (int i = 0; i < point_count; i++)
  {
    pntvec p = generate_point (point_scale);
    point_cloud.push_back(p);
  }

  // Write the point cloud file.  Open the file,
  //   write out the points, close the file.

  std::ofstream point_cloud_file("point_cloud.txt");

  for (int i = 0; i < point_cloud.size(); i++)
    output_point (point_cloud_file, point_cloud[i]);

  point_cloud_file.close();

  // Done, no errors.

  return 0;
}

/* Returns a random point in the range
 *  ([-scale..scale), [-scale..scale), [-scale..scale)).
 *
 * Parameters:
 *   scale - 1/2 the size the of 3D cube to draw from
 *
 * Returns:
 *   a random point within a centered 3D cube (scaled)
 */
pntvec generate_point (double scale)
{
  pntvec result;

  result.x = std::rand() / (double) RAND_MAX * scale * 2 - scale; 
  result.y = std::rand() / (double) RAND_MAX * scale * 2 - scale; 
  result.z = std::rand() / (double) RAND_MAX * scale * 2 - scale; 

  return result;
}

/* Writes the given point to the specified output stream,
 * followed by a newline.
 *
 * Note:  the & in the first parameter indicates pass-by-reference.
 * This avoids copying the output stream (which would likely fail).
 *
 * Parameters:
 *   file - a reference to an output stream (any output stream)
 *   point - a 3D point to write to the file
 *
 * Returns:
 *   nothing
 */
void   output_point   (std::ostream & file, pntvec point)
{
  file << point.x << " ";
  file << point.y << " ";
  file << point.z << std::endl;
}


