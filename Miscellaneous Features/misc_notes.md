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
