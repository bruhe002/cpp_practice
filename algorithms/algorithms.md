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

- Some functions take a lambda function as an argument
    - it will perform the operation of the lambda within the function

```
    equal(cbegin(lhs), cend(lhs), cbegin(rhs), cend(rhs),
        [](char lc, char rc) { return toupper(lc) == toupper(rc);});
```

- lambda has access to non-local variables
    - local variables must be references and initialized as a constant expression
    - can read but not modify these variables
- has access to static variables in the same scope
- lambda expressions can "capture" local variables
    - you put the variables inside the brackets
```

    int n{5};
    auto res = find_if(cbegin(words), cend(words),
        [n](const string& s) { return str.size() > n; });
```
- lambda with capture is implemented as a "functor with state"
    - has a private data member variable
    - captured variable is passed by value
    - cannot be modified
- to change a captured variable, we need to capture it by reference

`[&n](int arg) { return arg * n;}`

- we can make a lambda function capture all variables in a scope
    - \[=\] will capture all vars by value
    - \[&\] will capture all vars by reference
    - this can make tracking variables difficult to maintain
    - considered bad practice
- lambda functions in member functions are allowed to capture "this"
    - use \[this\], NOT \[=this\] or \[&this\]
- lambda expressions are mainly used for implementing temp functions
    - considered "first class objects"
    - we can store them in variables and pass to a function
    - best to use 'auto' as data type
    - we can return lambda expression froma a function
- "partial evaluation"
    - data is processed in stages
    - reduces computation
    - makes processing simpler
    - many applications in AI, database queries scientific computing etc
    - we can use lambda expressions with capture to implement partial evaluation
- returning a reference to a local variable is dangerous
    - variable will be destroyed when scope ends

## Pair Type
- defined in '<utility>' library
- has two public data members
    - first
    - second
- pairs can be used to return two related values
- a templated type
- need to specify the type of both members
    - `pair<int, int>`
- use "make_pair() to create a pair variable

## Insert Iterators
- an insert iterator inserts new elements to a container
- three types of iterator
    - back_inserter() returns a back_insert_iterator
        - adds new element to back of container
        - calls push_back()
    - front_inserter() returns a front_insert_iterator
        - adds new element to front of container
        - calls push_front()
    - inserter() returns a insert_iterator
        - takes a second argument: positional iterator
        - return value is an insert_iterator for the container