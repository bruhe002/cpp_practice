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

## List
- double-linked list
    - each node has a link to the previous node as well as the next node
    - can be easily traversed backwards
    - to indicate the first element, the previous pointer will be NULL
- pros/cons of list
    - adding/removing elements is faster than vectors
    - lists do not support indexing
    - accessing an element is slower
    - lists use more memory to store an element than vector
    - useful when adding/removing elements frequently
- can use push_back and push_front
- we can use iterators
- lists do not use RANDOM access
    - thus random access functions cannot be used
- list member functions are faster than their generic equivalent
    - reverse
    - remove
    - remove_if
    - unique
    - merge
    - splice

## Deque
- implements a Double-Ended Queue
- similar to vector but elements can be added in the front
- defined in <deque>
- implemented as a 2d array
    - has multiple memory blocks which each store several elements
    - vectors and list use one memory block
- has a push_front member functions
- if there is not enough room to store new element, 
    - it will just deallocate memory and allocate more
- deque is slightly slower than vector for most operations
    - faster for adding elements to the front
- lists is much slower than vector and deque for most operations and uses more memory
- vector should be the default choice

## Tree data structure
- each element has its own node
- a node has a key for the element
    - two pointers
        - left: contains a lesser key
        - right: contains a greater key
- first element is called a root
- advantage of this structure is seaching is very fast
- adding/removing is very fast as well
- might need to "rebalance" the tree
    - if all elements are less than the root, then it just becomes an array
    - need to choose a new root, move elements around until the tree is balanced again
    - "balanced-trees" auto rebalance themeselves
        - red-black
        - avl

## Sets
- an unstructured collection of elements
- an associative container
- an element consists only of a key, which MUST be unique
- elements of a set are stored in order
- set implemented as a tree (r&b)
- uses insert and erase
    - no push_front/back since none exist
- trying to insert an element in the set will return a fail
- insert() returns a pair object
    - second member is a boolean which is true/false whether success
    - first is an iterator to an element in a set
        - either new or existing if succeed and fail
- s.find(k) returns an iter to the element with key k
- s.count(k) returns the count of an element with key k
    - due to no duplicates, return value is either 0 or 1
- elements of a set are CONST
- cannot be reorders
- can use read-only algorithms
- very fast at accessing an arbitrary element
- insertion and deletion is very fast
- useful for checking membership
- useful when duplicate data is either not needed nor wanted

## Map
- std::map library in the <map> container
- associative container
- each element consists of a std::pair
    - the first member is the key of the element
    - second is the "value" of the element
- each element must have a unique key
    - values do not have to be unique!
- elements are stored in order
- for efficiency the map is implemented as a tree, usually a red-black tree
- key acts like an index
    - used to locate corresponding data
- insert and erase functions
    - add elements using a pair class
- map suports subscripting
- very fast at accessing an arbituary element
- insertion and deletion are usually very fast
- can be slow if the internal tree gets unbalanced
- \[\] provides an insert functionality
- if duplicates appear, the value gets overwritten
- if an exception is thrown, the partially populated element is left in the map
    - value is default initialized
- in C++17
    - introduced structured binding
    - easy way to access data structures

    ```
    for (auto [names, score] : scores) {  // Perfectly legal
        ...
    }
    ```

    - insert_or_assign(): function that takes a pair for a map
        - returns a pair, first value is iterator of the pair, 
            - second is a bool
                - true if inserted
                - false if assigned

## Multiset and Multimap
- similar to set and map, 
    - duplicate keys are allowed
    - does not utilize subscript operator
- if we use erase(), it will erase all duplicate keys
    - pass an iterator to remove a single element
        - we can use find() in a multimap to the first element with the key
        - count() will return the number of elements with a key
        - use these functions to loop through the keys and erase the iterator
- multimap and multiset have member functions to set iterator ranges of keys
    - upper_bound(k) returns iterator of first element with key k
    - lower_bound(k) returns iterator of last element with key k
    - equal_range(k) returns a pair of the upper and lower bounds of key k 

## Unordered Associative Containers
- associative containers store their element in an order which depends on the key
- sets and maps use a tree
- unordered associative containers use a hash table
- a hash table is an array of buckets
    - in this case a bucket is just a list
    - buckets are a linked list of pointers to the container's elements
    - index of the array is calculated from the element
    - "hash function" generates a number based on the key
- to insert an element, calculate hash number of the key
    - use it to know which bucket
- for efficiency, each element needs its own hash container
    - if the hash number is the same for two different keyys, this creates a "hash collision"
    - makes searching the bucket longer
- C++ provides unordered versions of most of their containers
    - unordered map
    - unordered set
- unordered containers only allow forward iteration
    - not useful since containers have no sense of order
    - unless iterating over the entire container
