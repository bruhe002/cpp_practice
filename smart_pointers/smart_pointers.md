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

## Unique_ptrs and custom deleters
- unique_ptr's destructor calls delete
    - this will be bad if the pointer was not returned by new
    - unique_ptrs can be created by passing an objects address, hence NO "new"
- we can provde a "deleter"
    - a callable object invoked by the deleter
    - deleter releases the resource as appropriate
- creat a lambda expression and use the type of the lambda as a second template parameter in the unique_ptr initialization
    - use `decltype` function to find out the lambda type

```
    unique_ptr<Obj, decltype(lambda_f)>p(&obj, lambda_f);
```

## The Handle Body Pattern
- splits classes into two parts
- "handle" is an outer class that provides interface to clients
- body is an inner class that provides the implementation
- when client creates a Handle Object, the handle creates a Body Object
- when a client calls a member function on the handle object, the call is forwarded to the body
- have a header for the handle, and the body
- clients include the Handle.h not Body.h
- if the implementation details change, only Body.h is affected NOT the Handle
- when making an update in the body.h, you can dynamically link the dll file into the executable

## The pImpl idiom
- in the Handle-body pattern
    - the handle has a private member which is a pointer to a body object
    - "pointer to implementation" - pImpl
    - also known as compiler firewall
    - handle.h declares the body class but does not define it
    - body object is allocated in the constructor
    - the body object is released in the destructor
    - need to consider the effects whether objects are copied or move
- can use a unique pointer for pImpl
- need to declare handle's destructor
- Clients do not need to include Body.h
- clients do not need to be modified if Body.h changes
- implementation is kept secret from clients
- requires extra memory
- loading a shared library increases start up time
- used in LARGE progects 
- used in QT (popular graphics library)
- could be used to write standard container classes

## Reference Counter

