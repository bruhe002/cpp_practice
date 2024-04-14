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
- lvalue reference to rvalue
    - we cannot bind an lvalue reference to an rvalue
    - unless the type is a const reference

```
    int& x = 3; // Error!
    const int& x = 3; // OK
```

- C++ has a concept of an "rvalue reference"
    - this is a syntactic device which indicates that a function argument must be moveable rvalue
    - the rvalue reference has '&&'

```
    void func(int&& x); // func's arguments is an rvalue reference

    func(2); // Will compile

    int y{2};
    func(y); // will not compile
    func(std::move(y)); // will compile
```

- `std::move()` will cast an argument into an rvalue
    - this will move the argument's data into the function parameter
    - y might not have a value or is unusable
        - must reassign to use again

## Value Categories
- lvalues persistent objects
    - occupy memory which is accessible to the programmer
- rvalues are stored in locations which are not accessible to the programmer
    - process registers
- C++17 have three categories
    - literals
    - temporary objects
    - lvalues

## Move operators
- we can overload functions so that it behaves differently based on a move
    - this is useful for copy constructor and assignment operator
        - move constructor
        - move assignment operator
- move function arguments should not be set as 'const'
- move operators should not throw exceptions 'noexcept'

- when writing a move operator for a derived class, we should call the corresponding operator for the base class
    - we must pass the argument as an rvalue

## Move-only Types and RAII
- to make a move-only class, implement the move operators and make the copy operators "deleted"

```
    class Test {
    public:
        Test(const Test&) = delete;     
        Test& operator=(const Test&) = delete;
        Test(Test&&) noexcept;
        Test& operator=(Test&&) noexcept;
    }
```

- C++ has some types which cannot be copied but can be moved
    - fstream, iostream
    - Classes used in multithreading
    - smartpointer class
- all follow the RAII idiom

- C++14 has "generalized" lambda capture
    - a variable in the outer scope can be moved into a lambda-local variable
    - this allows capture by move

## Special Member functions in C++11
- move constructor
- move assignment operator
- a compiler will only synthesize a move operator if
    - the class does not define a copy constructor, assignment operator or destructor
    - Every data member of the class is either:
        - built-in type
        - user-defined type with move operators
        - static data member(not moved)
- if a class defines a move operator, both the copy operators will be synthesized as "deleted"
- if a class needs a destructor, it probably needs a copy constructor and assignment operator
- Rule of Five
    - Destructor
    - Copy constructor
    - assignment operators
    - the 2 move operators