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
    