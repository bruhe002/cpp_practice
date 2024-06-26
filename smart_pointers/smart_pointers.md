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
- a technique for allowing different objects to share the same resource
- an integer used to store the number of objects sharing the resource
- initially zero
- when bounded, the number is incremented
- when unbounded, counter is decremented
- the number is allocated on the heap
- constructor allocates the counter
- when an object is destroyed, we decrement the counter
    - if counter is 0, "this" is the only remaining bound object
    - should release it from memory
- for an assignment operator
    - `s2 = s1`: if s2 is bound to different memory, we must first unbind s2 from its memory
        - decrement s2's counter

- for move constructor, do not increment the counter
    - add shallow copy of the counter pointer
    - set the moved-from object's counter to null as well as the data pointer
    - modify the rest of the code to check the counter before dereferencing it
    - it just transfers the binding from one object to the other object

## Shared Pointer
- introduced in C++11
- uses reference counting
- allows differenet shared_ptr objects to share a memory allocation
- has a private data member which points to allocated memory
- other private member which points to control block
    - control block contains the reference number
- defined in <memory>
- make_shared() is the function to allocate memory
- can move a unique_ptr into a shared_ptr
    - cannot go the other way arround
    - if we use a new() call, that will be allocated separately, 
        - its an extra call to new()
        - control block might not be in sync with memory
- when different threads copy or assign shared_ptr objects which use the same control block, this causes a data race
- to prevent this, the reference counter is "atomic"
    - operations on atomic variables are mush longer
- unique_ptr has same overhead as traditional pointer
- shared_ptr has more overhead
- only use a shared_ptr when needed
    - useful where different objects need to have access to the same area of heap memory

## Weak Pointer
- a non-smart pointer
- provides a safe way of aliasing a shared-ptr
- this avoids the problems with traditional pointers which can "dangle"
- weak_ptr is bound to a shared_ptr object
- does not affect reference count
- cannot access the shared memory directly
    - has to be converted back to a shared_ptr
    - only allowed if the shared_ptr is valid
- the lock() member function returns the shared_ptr if it is still valid
    - returns nullptr otherwise
    - we can also copy the weak_ptr  into a shared_ptr
- applications
    - cahce implementation
        - data stored in shared_ptr objs
        - chache holds weak_ptr to data
        - use lock() to retrieve data
        - original data returned if not expired
            - otherwise need to fetch again
- cycle prevention
    - a parent and child object that have shared_ptrs to each other
        - reference counter never hits zero
        - resources are never released
        - destructors never get called
    - if we make son's ptr a weak_ptr,
     the reference count can be zero