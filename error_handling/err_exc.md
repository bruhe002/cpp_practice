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