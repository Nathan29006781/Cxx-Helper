# Cxx-Helper
A collection of functions I think would be useful to have in C++.

<h2>Notes:
*Can be used by public, but not fully ready for use

*C++20 dependent
</h2>

Here is a list of features and what each offers:
1. Colours
* Terminal colours modification
* Splitting into RGB channels
* Inversion and darkening of colours
* RGB <-> HSV conversion

2. Containers/Ranges
* Range Analogues to STL algorithms
* Circular Queue
* Check for element in container range or numerical range

3. Printing
* Stream operators for
  * Iterators
  * Containers (Arrays, Tuples, Linked Lists, Multi-Dimensional Containers...)
* Type-safe printf
* Automatically Timestamped Prints

4. Iterators
* Iterator Base Class to avoid boilerplate code
* Iterator Pair Struct constructible from a variety of views

5. Time
* Timer using std::chrono units

6. Types
* Concepts for Number Systems
* Default type-alias for Number Systems

8. Random
* RNG
* Random Container Modification

9. Sorting
* Iterator and Range versions of sorting algorithms
* Step-by-step view

10. Enumerations
* Enum Operators

11. Constants
* Mathematical Constants with symbolic variables
* Consteval square root implementation

12. Math Functions
* Common Math Functions
* Variadic versions of number operations (lcm, hyp...)

13. Geometry
* 2D Vector
* Coordinates
* Angles
  * Typed for radians, degrees...
  * Complex Functions
  * Trigonometric Functions
  * Classification (obtuse, complementary...)

13. Utilities
* Convenient macros for control structures
* Debugging Macros
* Bool <-> Signum Conversion