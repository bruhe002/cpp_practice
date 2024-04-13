# Move Semantics

- with move semantics, we can save time by "moving" data in and out of function calls
- C++ uses value semantics
    - arguments are passed by value
    - arguments are returned by value
    - avoids the needs for a garbage collector
    - requires copying of objects
        - this increases execution time

- Move semantics introduced in C++
    - optimization over copying objects
    - if the source object is an "rvalue", its data can be moved into the target instead of being copied
    - similar to moving files between folders instead of copying them

## Lvalues or Rvalues
- an object can either be an Lvalue or an Rvalue
    - objects on the left of the assignment operator is Lvalue
    - the other is an Rvalue
    - this rule is deprecated
- NOW an lvalue represents a NAMED memory location
    - it has a name
    - we take its address using the & operator
    - anything else is an rvalue
- both L and R can be passed by value
    - lvalues can be passed by reference
    - rvalues cannot be passed by non-const reference
        - however, rvalues can be passed by const reference, 
            - since it mimics pass by value behavior
- in c++11 the argument can be moved if:
    - object is an rvalue
    - the type is "moveable"
- objects WILL be copied if obj is an lvalue
    - or if type is not moveable

## Lvalue and Rvalue References
- a reference to an lvalue is typically implemented as a pointer
- the compiler adds code to deference the pointer as needed
    - this requires that x has name and an address
        - ie x must be an lvalue
        - this is known as an "lvalue reference"