## Constructors in Modern C++
- Data members are default-initialized if not set in the constructor
    - initial values are usually undefined
- Copy constructor is a specialized version of the constructor
    - takes one argument -> object of the same class

```
Test test1{x,y};

Test test2{test1};
```
- assignment operator is a member function
    - operator '='
    - returns object by reference, not const reference
    - parameter is a const reference
    `Test& Test::operator=(const Test&);`
    - we write an assignment operator if the desired behavior is different from the compiler
    - compilers set an assignment operator by default

## Synthesized Member functions
- new member functions in Modern c++: move functions
- destructors
- default constructors are automatically initialized if not defined

## Shallow and Deep copying
- *Deep Assignment*
    - we need to provide the target object with its own memory allocation
    - must be large enough to  hold the data
    ```
    delete [] data;
    data = new char[arg.size];
    ```
    - before we need to check for self-assignment
        - `this` and `arg` could be the same object
- Rule of three: if you need to implement one of the big three,
    - copy constructor
    - assignment operator
    - destructor
    - probably should implement the other two

## Copy Elision
- the compiler is allowed to skip over a call to the copy constructor in some cases
- usually occurs when copying temp objects during function calls
    - even if the copy constructor has side effects
    - you can disable it in compilers
- return value optimization
    - harder for compilers to do than for temporaries
    - may not be done in some cases
- copy elision can also occurs when an object is passed by value

## Conversion Operators
- a class can define a conversion operator
- a member function which converts an object to come other type

```
Test test;
int x = test + 5;
```
- First tries to find an exact match for an addition operator
- if that fails it looks for a conversion operator
    - this is implicit casting
```
class Test {
    int i{42};
    string str;
public:
    operator int() const { return i; }
};
```
- conversions can be explicit or implicit
    - use the `explicit` keyword in the function signature
- do not need to use a cast in a conditional
    - a bollean cast is uneccessary
- constructors with a single argument, acts as an implicit conversion operator
    - **WARNING** This can cause unexpected results
        - e.g when passing a Test Object as a function argument

## Deafult and Delete Keywords
