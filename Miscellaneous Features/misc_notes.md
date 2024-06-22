# Miscellaneous Notes

## Chrono Library
- handles time and dates
- C had a `<ctime>` library
    - low level and poorly designed
- `clock()` returns the number of clock tickes since the program started
    - stored in a variable of type clock_t
- `time()` takes a variable of type time_t by address
- "chrono" has three timportant concepts
    - clock
        -start date(epoch) and tick rate
    - time point
        - the number of clock ticks since the epoch
    - duration
        - an intercal between two time points, measured in clock ticks
- Duration types:
    - integer types which represent units of duration
        - seconds, hours, minutes, nanoseconds etc
    - duration units are default initialized
    - duration types have literals
        - `auto hour = 5h;`

    - cannot be printed out directly
        - `count()` member function returns the numeric value of the duration
    - constructor is explicit
        - NEED a duration literal , not an integer
        - conversion operators are also explicit
            - `seconds sec = 2s; // Correct`
        - conversions between durations can be implicitly done if there is no loss of data
            - hours -> minutes = CORRECT
            - milliseconds -> seconds = BAD

- Clocks
    - chrono provides three clocks
        - system_clock
            - measures wall time
            - similar to the one in C library
            - best clock for interactive use
                - relates to calendars, watches etc
            - not well suited for measuring time intervals
                - clock may be corrected if it runs fast or slow
        - steady_clock
            - idealized clock which only goes forward
            - best for measuring time intervals
            - goes one tick at a time (monotomic)
            - system_clock::now() returns the current time point
        - high_resolution_clock
            - clock with the shortest tick period supported by system
- Time Point
    - represents a point in time
    - contains a duration representing the time interval since the clock's epoch
        - a time_point object is associated with a particular clock
    - two time points can be subtracted and return a duration
    - `sleep_for()` function in the "threads" library which will pause an application based on the argument passed
    - in a single-threaded program, the main program will sleep

## Bitsets
- library `<bitset>`
    - an abstraction which represents a group of bits
    - std::bitset is a timplated type
    - the parameter is the number of bits 
```
    bitset<8> b1{"10101110"};
    bitset<8> b2{0x05};
```

- bitsets can be used in streams
- has a size() member function
- can use subscript notation to grab a bit
- test() accesses a bit with bounds checking
- bit member functions
    - set(idx, true | false)
    - reset() // sets all bits to false
    - flip() inverts all bits
    - all() returns true if all bits are set
    - any() returns true if at least one bit is true
    - none return true of no bits are set

## Tuples
- pair is a compound type
    - two members of any type: first and second
    - can create explicitly or with function "make_pair"
- tuples are in the `tuple` library
    - similar to pairs but can have a fixed number of elements
        - we can use a "make_tuple" function to create one
    - to access members we use the templated `std::get()` function
        - use the element's index as the template parameter
        - `auto x = get<0>(numbers)`
- unpacking a tuple
    - `std::tie` function unpacks all the elements in a tuple ina variable

```
    double d;
    int i;
    string s;

    std::tie(d, i, s) = numbers;
```

- use tuples if we want to store data in the short term that
    - doesnt need a member function
    - isnt important enough to merit making a new type
    - has elements of different types
- traditionally we would use a struct to return multiple values from a function call
    - tuples requires much less code when returning multiple values

- tuples in c++17
    - constructor template argument deduction
        - `tuple tup{1, 1.2, "hello"};`
    - structured binding can be used to unpack tuples
        - `auto [d, i, str] = func();`
    - function `apply()` unpacks the elements to acts as arguments of a function

    ```
        void func(int, double, string);
        apply(func, tuple(1, 2.0, "three"s));
    ```

    - can use tuples in constructor calls using function: make_from_tuple()

## Unions
- a union is a compound data structure
    - each member of a union must have a distinct type
    - all members are stored at the same address
    - only one member can be in use at a time
- main application of unions is processing data that can exist as more than one data type
- all members of a union are public by default
- unions can have member functions but not virtual member function
- unions cannot be a base or derived class
- only safe to read the member "in use" 
    - members not in use are undefined
- tagged union: 
    - unions are highly error-prone
        - programmer has to remember which type is in use
    - unions can be made safer by adding a "tag" member
    - this indicates which member is in use ( a tagged union )

- a tagged union requires the programmer to check before accessing a member
    - programmer must also set the type when bringing a member into use
- for greater safety, wrap the tagged union inside a class
    - union is a private member of the class
    - can only be accessed through the class's public member functions
    - these perform the safety checks necessary when working with unions
- C++ std::variant ( defined in variant header )
    - similar to a wrap tagged union but
        - type safe
        - can have different alternatives of the same type
    - variant can deduce the type of argument that is assigned to it
    - use `get()` function to grab an alternative
        - can also get via index
    - `std::holds_alternative()` checks to see if an alternative is in use

## Mathematical Types
- `std::valarray`
    - vector like type based on FORTRAN arrays
    - Fixed size
    - easier syntax for numerical operations
    - Not widely used
        - poorly designed
        - compiler implementers not interested in optimizing it
        - better to use a third-party library (Eigen, Blaze, Armadillo)
- `<complex>`
    - templated type
    - parameters can be float, double or long double
        - first parameter is the real number
        - second one is the imaginary number
    - can do mathematical operations and logical operators
    - literal suffix i, which makes a double imaginary
    - non member functions
        - abs()
        - arg()
        - exp()
        - pow()
        - conj()

## Bind
- bind() takes a callable object as its first argument
    - bind() performst a partial function call
    - it "binds" the remaining arguments to this object and returns a new callable
    - can allow multiple arguments to bind to the function
        - use placeholders _1, _2, ... to know thier argument position
        - can put arguments in a different order
        - this is called "Argument forwarding"
    - this is equivalent to a c++14 lambda which creates a local variable

## Callable Objects
- a callable object supports the () operator
    - pointer to non-member function
    - functors
    - lambda expressions
    - objects returned from calling bind
- sometimes we want to work with different callable objects which have the same signature
- C++ has a `std::function` in `function` library
    - the class has a private member which can store a callable object
    - template class
        - object's signature is a parameter
    - std::function performs "type_erasure"
- we can declare as function argument as type std::function
- we can create a container whose elements are of type std::function
- function prototype must match the template parameter
    - does not support overloading
- run-time overhead
- invoking the callable object involves indirection
    - similar to virtual function overhead
- should only be used when we need a polymorphic function object
- for storing a callable object in a variable use "auto"

## Member function pointers
- we can define a pointer to a member function of a class
- their use is more complicated than with function pointers
    - requires a different syntax
    - may need to provide the "this" pointer
    - member function pointers cannot be called directly
        - must be explicitly dereferenced

    ```
    class Test {
        ...
        void func(int a, const string& b);
    };

    // Define pfunc as a pointer to a member function of test
    void (Test::*pfunc)(int, const string&);

    // Make pfunc point to the member function
    pfunc = &Test::func;  // The & is not optional here

    // Make an object
    Test test;

    // access the pointer as a member of the object then we dereference it
    (test.*pfunc)(42, "Hello"s);
    ```

- `std::mem_fn()` takes a member function pointer as argument and returns a callable object
    - `auto f = mem_fn(pfunc);`
    - to invoke, we need to pass the object to the function call
        - `f(test, 42, "hello");`

## Interfacing to C
- many interfaces are written in C
    - operating system API
    - Database API
    - Third Party libraries and frameworks
    - languages with "foreign function" interfaces
- C is almost a complete subset of C++
    - almost any C program is legal in C++
- always simple to compile the entire program's source code in a c++ compiler
    - this might not always work though
- interfacing with C at the binary level requires 
    - a header file which declares the function in the C interface
    - the compiled binary code for the funtions
    - this can be an object file, a static library or a DLL/shared object
- the C and C++ compiler used must be compatible
    - same object file format
    - same function call conventions
    - same word size
- if any C++ features are used, use a C++ compile
- Name Mangling
    - in C, a function has the same name in the binary object file as it does in the source code
    - in C++, the compiler "mangles" the name
    - required to support function overloading
    - does not occur in C
    - to make C++ binaries compatible with C, we use the `extern "C"` directive
        - tells the C++ compiler not to mangle the function name

- Exporting to C
    - when writing a C++ function that will be called from C
        - use bult-in types only in the interface
        - can only use arrays and pointers to built-in types
        - or structs which have members of built-in types only
        - place functions in the global namespaces
            - C has no concept of namespaces

- conditional compilation
    - interface header will be processed both as C and C++
    - it may contain some things which are not valid C
    - we can use the __cplusplus preprocessor symbol
        - defined by C++ compilers but not by C compilers
    - use a conditional compilation to hide things from the C compiler

- resource management
    - C uses malloc and free
    - C uses raw pointers for resource management
        - no destructors, no RAII, no smart pointers