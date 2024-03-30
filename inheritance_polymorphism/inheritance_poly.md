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
