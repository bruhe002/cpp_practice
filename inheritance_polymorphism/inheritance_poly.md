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