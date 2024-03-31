# Inheritance and Polymorphism

## Classes and Inheritance
- programmers often work with entities which are related or represent similar concepts
- a class heirarchy can express these relationships
    - makes it easier to reshape the code between them
- class at the top of the heirarchy is called the "base class"
    - it is the most generic
    - classes below are called the "subclass" or the "derived class"
        - subclasses "inherit" from the base class
        - models an "is-a" or "is-a-kind-of" relationship
    
```
    // Aeroplane Inherits from Vehicle
    class Aeroplane : public Vehicle {
        ...
    };
```

- derived class will be able to call the nonprivate members of a superclass
- the superclass gets initialized before the subclass
- derived class has to call the constructor of the parent class

```
class Aeroplane : public Vehicle {
    // Initialize the vehicle part of the object
    Aeroplane(int max_speed, int max_height) : 
        Vehicle(max_speed),
        max_height(max_height) {}

    ...
};
```

- derived classes can also be superclasses to other derived classes

## Member Functions and Inheritance
- a child class inherits all non-private member functions of its parent class
- a child class can re-implement the parent class's member function for its own function
- extending member functions
    - child classes can call the parent functions using scope operator - ::

    ```
        class Airplane : public Vehicle {
            void start() {
                ...
                Vehicle::start()
                ...
            }
        }
    ```

- "protected" keyword allows child class use members from parent that no other code has access to
    - think of "private but only for the family"

## Overloaded Member functions
- we can overload inherited member functions
- we write a new member function definition with a diffferent signature
- hidden member functions
    - if we overload an inherited function in the child class, 
        - it will "hide" all the other inherited member functions with that name
            - they cannot be called with the child class
            - this is inconsistent with OO design principles
            - one solution is to define the inherited functions in that class
                - this could be a lot of work
                - in C++11, we can use the "using" keyword to use the parent's version
                
                ```
                using Vehicle::accelerate;
                void accelerate(int height) {
                    ...
                }
                ```

## Pointers References and Inheritance
- Normally a pointer must point to a variable of the same type
- a pointer to a base class can point to any object in the same hierarchy

```
    class Circle : public Shape {};

    Circle c;
    Shape* pshape = &c;

```
- however, we cannot go in the other direction
```
    Circle* circle = &shape; // Error
```

- this works due to how memory is allocated for parent and child classes
- depending on how the variable is defined, it will only have access to that data's member functions
    - `Shape* s = new Circle` -> s is seen as a Shape first and will not have access to Circle's members

## Static and Dynaminc Type
- static type is the type used in the variable declaration
```
    Shape *pshape = &circle; // Static type is Shape
```

- Dynamic Type is the type of the variable in memory
```
    Shape *pshape = &circle; // Dynamic type is Circle
```

- C++ almost always uses static typing
    - dynamic type is only used for a pointer or reference to a base class

## Virtual Functions
- Static Binding
    - compiler will decide which function is called
    - done using the static type of the object
- Dynamic Binding
    - code decides which function is called in an object
    - two conditioons must apply 
        - a member function is called through a pointer or reference to a base class
        - member function was declared as "virtual" 
    - a child class which implements a virtual function "overrides" it
- virtual functions solve the problem with function call arguments
- to override
    - function must have the same signature as the parent
- overloading a function disables dynamic binding
    - may hide the parent's member function
- C++11 introduced the "override" keyword
    - tells compiler to check whether the member function overrides a 
    virtual member function in the parent class
    - `void draw() const override {...}`
    - `void draw(int) const override {...}`
- C++11 also introduced "final" keyword
    - a class that cannot be derived from
    - the leaf of the hierarchy

## Virtual Destructor
- if a destructor is non virtual, static binding will be used
    - only the static type destructor will be called
- if it was virtual, the derived destructor is called, then the parent destructor
- default contructors are NOT virtual

## Interfaces
- typically base classes model abstract concepts such as "shape" or "vehicle"
- derived classes are more concrete
- base class is the INTERFACE to the class heirarchy
- it's public virtual member functions provide all the functionality that is common to hierarchy
    - derived classes override these function
    - implement the interface in a concrete way that's specific to them
- bass class's virtual member functions cannot do anything useful
    - can be left empty
    - show that they are not implemented here
        - set function "= 0"
            - shows it is an abstract base class
- derived class must override all the pure virtual functions
- cannot instantiate an abstract class
    - will cause a compiler error
- if a function takes a parent object argument by value, 
    - all child class arguments will be treated as the parent
    - will use the parent copy constructor
- cannot pass abstract base class by value
    - will not compile