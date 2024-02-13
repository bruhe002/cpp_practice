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


##  Algorithms with _if versions
- algs come in two versions
    - base version
    - an _if() version which takes a predicate argument
        - ex - find_if()


## Lambda Expressions
- writing a predicate function within the function call
- Modern c++ has lambda expressions
    - anonymous "local" functions
    - compiler will issue it a unique name
    - defined inline
- use `[]` as function name
    - write function the normal way
```
    [](int n) {return (n % 2 ==1);}  // Return typed deduced as bool
```

- if we want to specify a return type we need to specify the following
```
    [](int n) -> bool {
        ...
    }
```