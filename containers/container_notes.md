# Containers

## Sequential Containers
- std::string and std::vectors
- data is stored in an order which is determined by program
- data will remain in the same position unless program performs a change

## Associative Containers
- order depends on data
- elements have a key that identify it
- key determines position of element
- std::sets and std::mpas
    - sets are unstructured collection of elements
    - maps similar to directory and hash maps
- do not support push_front or push_back functions
we can use iterators to loop through them

## Container Adapters
- data structures which are implemented using sequential containers
- queues and stacks
- data stored depends on when the data is added

## Std Library array
- faster than vectors and directly compatible with C code
- no direct way of number of elements
    - need a separate var for it
    - when passing to a function, need to pass the size as well
- silent conversion to pointer
- arrays cannot be assigned to each other
- arrays are templated types
    - parameters are the element type and the number of elements
- std:array object can only be created on the stack
    - must know the num of elements at compile time
    - in <array> library with its own functions

```
std::array<int, 5> arr{1,2,3,4,5};

for (auto it = begin(arr); it < end(arr); it++) {
    ...
}
```

## Forward Lists
- each element has its own allocation ("node")
- use of pointers to point to the next node
- last node will contain an invalid pointer to indicate it is last
- found in <forward_list> library

