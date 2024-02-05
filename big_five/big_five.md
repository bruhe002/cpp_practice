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
- Modern c++ allows programmers to force the compiler to initialize special member functions
- `=default` can call the default constructor
- advantages of default member functions
    - easier to see which special member functions the class has
    - avoids tedious code
    - updates constructors
- you can prevent this by making constructors private
- a *deleted* function is defined but cannot be called on
    - any function can  be deleted (non/member)
    - mostly used for conversion operators and default constructors

## Operators and overloading
- c++ defines operators for built-in types
    - e.g. + addition operator
    - == equals operator
- operators take either one or two arguments
- operators can be member functions or non member functions
- unary operators are usually member functions
    - vice versa for binary
- we can define operators for our own class (operator overloading)
- must use the same symbols as the built-in operators
- must have similar simantics/syntax
- +, -, *, / operators are really only useful for mathematical classes
- most useful operators to overload are:
    - assignment
    - equality
    - inequality
    - less than
    - function call operator
- you should NOT overload LOGIC operators, 
    - address-of &
    - comma ,
    - scope ::
    - dot operator
    - ternary

## Friend Functions
- Normally a non-member function can only access a class's public members
- the class can declare a non-member function to be a "friend"
    - this allows the function access to all the class's members
    - not recommended because it reduces encapsulation

## Member and non-member operators
- most operators can be both
    - usually should be member
    - provides access to private data
- operators that change the state of the object are best implemented as member functions
- operators which are closely related to member types are best implemented as member functions
    - some can only be defined as member functions
        - assignment
        - subscript
        - function call
        - arrow
- nonmember overloaded operators can work with literal values
    - e.g. string concatenation
- binary operators which require a type conversion argument should be non-member functions
    - input and output operators should be non member as well