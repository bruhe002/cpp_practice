# Smart Pointers

- the "traditional" pointer was inherited from C
- a built-in type
- a pointer variable stores a binary number which represents and address in memory
- can represent the address of a stack variable
- can be used to manage memory on the heap
- drawbacks of traditional pointer:
    - no concept of ownership
        - any code that uses a pointer can reassign it
    - no destructor
    - rarely needed in C++11
- smart pointer are classes which encapsulate allocated memory
    - implemented using RAII
    - smart pointers has ownership of the allocated memory 
    - allocated memory can only be accessed through public member functions
- `auto_ptr`: first smart pointe
    - transferred allocated memory when copied
    - unpredicatable behavior when auto_ptrs were stored in containers
- `unique_ptr`: a fixed version of auto pointer
    - cannot be copied or ssigned to
    - memory can be transferred to another object tho
        - use of std::move()
- `shared_ptr`: shares the allocated memory with other shared_ptrs
    - reference counting is used to manage the memory
        - memory is released when no more objects are pointing to it
    - similar to garbage collecting languages
    - more overhead than uniqu_ptr

## unique_ptr
- allocates hgeap memory in its constructor and has sole ownership of it
- program does not need to manage memory
- unique_ptr is defined in <memory> header
    - its a template class
    - move-only class
- to initialize, we call new() explicitly

```
    unique_ptr<int> p1 {new int(43); }
```

- can allocate a fixed-size array
- there is a `make_unique` function
    - calls new() internally
    - uses perfect forwards its arguments to the constructor
- we can pass a unique_ptr to a function using pass-by-move
    - we can return unique_ptrs as well
        - object is moved into the function's return space
        - this transfers ownership of the allocated memory
        - object is moved again into the variable caller

## Unique_ptrs and polymorphism
- polymorphism is when we use a base class object to represent a derived class object
- in C++ this requires either a pointer or a reference
- we can use unique_ptr in polymorphism

```
    unique_ptr<Base> pbase { make_unique<Derived>(); }
```

- The Factory Pattern
    - programmers often call a function to create a new object
    - function decides the type of the new object and returns a pointer to it
        - known as a factory pattern
        - useful in class hierarchies
        - create a child class object and return it through pointer to base
    - easier to add more classes into the heirarchy
    - create a unique_ptr as a local variable
    - return the pointer from the function
    - caller's unique_ptr will automatically release the memory when it goes out of scope