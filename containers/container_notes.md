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