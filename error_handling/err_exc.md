# Error Handling and Exceptions

## Error Handling
- errors can still occur even if code is perfect
- when an error occurs
    - we need to communicate with the user
        - either try again
        - or ignore
        - only exit the program as a last resort
        - avoid communicating information that is not helpful
- errors can be handled when they occur
    - sometime useful to handle errors in different parts of the code


## Error Codes and Exceptions
- in C, a function returns a coded number that corresponds to the errror
    - caller checks the return value
    - caller can hand le the error itself
    - when an error occurs the function returns a value that correspomds to the error
- error codes make code more complicated
    - requires more if statements for every error scenario
    - caller has to check return value
    - can create maintenance problem
    - large switch statement
    - do not work well with callback functions
    - C++ constructors cannot reurn an error code
- C++ provides "exceptions"
    - code which could cause a run-time error is put isnide its own scope
    - programmer specifies the type of error it is to know how to solve it
    - avoids a lot of tedious and error-prone coding
    - exception objects can convey more information
- exceptions do require extra code to be executed at run-time
    - throwing an exception takes longer than returning an error code
    - overhead from exceptions can be detrimental
    - some C++ coding stadards forbid exceptions

## Exceptions
- std::exception
    - any type can be used for an exception object, including built-in types
    - exception calss gives a consistent interface to exceptions
    - std:exception is the base class of an inheritance hierarchy
        - number of sub-classes
        - function `what()` returns a C-style string describing the error

## Try and Catch Blocks
- "catch" can only come after "try"
    - can have more than one catch block
    - can add a catch block for each static type
    - exception will be handled by the first catch block that can handle it
- exception handler should take exception object by reference
    - allows polymorphism to work
- program maybe in an unstable state
    - avoid allocating memory
    - don't create new variables
    - keep code short vary simple
- nested try...catch blocks are allowed 

## Catch-all handlers
- we can write a catch handler with "..." that can handle any type of exception
    - `catch(...)` can handle code at any exception
- best to put a catch-all handler after all other catch blocks
    - catching any exceptions that have been missed
- Useful for testing your code
    - not so much for debugging
    - no information about the error condition
    - does not capture other events
        - unix signals

## Exception Mechanism
- thrown object is copied into a special area of memory
    - not part of normal stack
    - set up by compiler
    - any local variable in scope is destroyed
    - program immediately leaves scope
        - does not execute any further instructions
- program will look for a suitable handler
    - if it gets to main without finding one, program calls std::terminate()
    - destroys local variables
    - called "stack unwinding"
- to "rethrow" an exception, use `throw` keyword with noargument
    - will find another handler outside of current scope that can catch the rethrown exception
    - this is useful
        - log exception at a point where it happens
        - add extra information to the exception
        - convert the exception to a higher type

## std::Exceptions SubClasses
- bad_alloc: memory allocation errors
- bad_cast: when dynamic_cast fails
- out_of_range: out of range access
- invalid_argument: argument type is not acceptable
- domain_error: argument value is outside the domain
- length error: length limit of object is exceeded
- overflow_error
- underflow_error
- range_error
- c++ do not use exceptions all that much due to overhead and speed

## Exceptions and Special Member Functions
- when an exception is thrown, the destructor is called for all local variables
- what happens when a destructor throws an exception
    - if no catch block IN the destructor two stack unwinds could occur
    - C++ will only assume one
        - leads to undefined behavior
- destructors should never throw exceptions
    - exceptions should be handled IN the destructor
    - destructors should also just release resources
- constructors can throw an exception as well 
    - it will destroy the partially created object and all data members
    - exceptions should be handled by the caller
    - constructors can also throw esceptions to report errors to the caller

## Custom Exception Class
- we can write our own Exception class
- best to derive from on of the subclasses of exception
- we do not derive directly from std::exception
- class needs constructors which take a string
    - needs copy constructor
    - can override the what virtual member function
    - can have data members to store information
    - object should be lightweight