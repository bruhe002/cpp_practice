## Algorithms

- an algorithm is a set of steps used to solve a problem
- often refers to techniques to searching and sorting through data

- why use?
    - wide range of features
    - shorter/clearer code
    - highly flexible
    - code reuse

- generic algorithms
    - STL algorithms that work on any kind of container
    - typically, is passed a begin and end iterator
        - will perform function over that range
        - will either return
            - an iterator of the element
            - the value of the iterator

```
    auto res = find(cbegin(str), cend(str), 'I') // 'res' will be an iterator
```


## Algorithms with predicates

- many algs call a function on each element which returns bool
    - known as a "predicate"
- these algs allow us to supply our own predicates
    - ex - sort() function