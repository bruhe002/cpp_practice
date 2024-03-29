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

## Searching Algorithms
- std::string has member function "find_first_of()"
    - there is a generic function, std::find_first_of()
- "adjacent_find()" looks for two neighboring elements that have the same value
    - returns an iterator of the first element match
- std::search_n() looks for a sequence of n successive elements that have the same given value
- search() looks for an occurrence of the second iterator range
- mismatch() takes two iterator ranges and looks for differences between the two ranges
    - returns a pair to each element
- all_of() is also a function -> look it up
- binary_search() is similar to find()
    - much faster

## Numeric algorithms
- iota(): populates an iterator range with values that successively increase by 1
    - takes an iterator range and a starting value
- accumulate() returns the sum of the elements in a given range
    - default the operation is addition
    - we could pass a callable object to operate
    - algorithm is sequential 
    - cannot be parallelized
- reduce() is an alternative implementation of std::accumulate() which is compatible with
parallel execution

## Write-only Algorithms
- write to an iterator range, but can not read them
- fill()
- fill_n()
    - these functions are dangerous since they don't check vector size
    - use blocks to protect from a crash
- swap()
- generate()
- generate_n()
- look these ups

## For-each Algorithm
- for_each() calls a function on every element in an iterator range
    - function can take elements by reference allowing us to change elements
    - usually better to write a range-for loop now
    - shorter and clearer
    - can use break and return statements
    - for_each can be applied to a sub-range of elements
    - single path through code makes it easier to optimize

## Copying Algorithms
- copy elements into another range
- copy() is most basic
- copy_if() copies elements in which a predicate is true

## Write Algorithms
- changes elements in an iterator range
- replace() changes elements with a given value to another value
- replace_if() changes all elements for which a predicate returns true
- _copy() versions of algorithms
    - algs which change the elements have two versions
    - writes data to a different iterator
    - ex: replace_copy(), replace_copy_if() 

## Removing Algorithms
- remove elements from a container
    - removed "logically"
    - still physically present in the range
- range()
    - the removed element is moved to the back of the container
    - value is no longer defined
    - size will stay the same
- erase()
    - physically removes elements
- remove_if() takes a predicate
- _copy() versions write to a destination
- unique(): deletes duplicate elements
    - could also take a predicate

## Transform Algorithms
- will call a given function on every element in the range
    - result is copied into a destination
- transform() performs a transformation between two vectors
- in_place transformation
    - destination iterator is allowed to overlap the source
    - allows us to do an inplace transformation

```
transform(begin(vec), end(vec), begin(vec), ...)
```

- transform is overloaded
    - takes a second iterator range

## Merging Algorithms
- take iterator ranges, assuming they are sorted, and takes the elements and writes them to a destination
- merge() combines two sorted iterator ranges into a destination
- set_intersection() combines two sorted iterator ranges into a destination
    - destination will only contain elements contained in both ranges
- set_union() combines two sorted iterator ranges
    - destination will contain elements in both containers but only once

## Reordering algorithms
- re-arranges elemnts inside an iterator range
- does not change value
- reverse() takes the elements in an iterator range and reverses their order
- rotate() rotates elements around a pivot

## Partitioning Algorithms
- we can partition the elements in a container into two groups
    - elements with a given property are at the front
    - elements without it are sent to the back
- can be useful
    - drop down menus
- partition() takes an iterator ranges and a predicate function
- stable_partition() elements within a group will keep their relative order
- partition_point() can be used to find a partition point of a partitioned container

## Sorting algorithms
- puts elements in a range in a order
- usually implements "quick sort"
- sort()
    - can supply a predicate function as an optional argument
- is_sorted_until() returns an iterator to the first element which is not in order
- partial_sort() sorts a subrange of the container
    - takes an extra iterator which uses the offset to know what to sort
- nth_element() rearranges the elements so that the iterator points to the element 
that would be in that position if the range was sorted

## Permutations
- possible arrangement of elements of a specific set or range
- a set of every possible arrangement of elements
- next_permutation() takes an iterator range
    - reorders the elements to give the next permutation in ascending order
    - returns a bool depending on whether there is a next permutation
    - uses < operator by default but can be passed a predicate
- prev_permutation() gives the previous permutation
    - elements must be sorted in descending order
- is_permutation takes two iterator ranges
- returns true if they are permutations of each other

## Min and Max Algorithms
- Returns the largest and/or smallest element
- max_element()
- min_element()
- maxmin_element()

## Further Numeric Algorithms
- partial_sum() writes the running total of the elemets into another container
    - can be used to perform numerical integration
    - given {a,b,c,...}
        - target container will contain {a, a+b, a+b+c, ...}
- adjecent_difference() writes the difference between successive elements into another container
    - given {a,b,c,...}
        - target container will contain {a, b-a, c-b, ...}
- inner_product() will multiply the corresponding elements between two containers
    - given {a1,a2,a3,...} and {b1,b2,b3,...}
        - result will be a1\*b1 + a2\*b2 + a3\*b3
    - equivalent to transform() followed by accumulate()
    - can be overloaded by providing different binary functions instead of the default + and *
        - replace * with "transform" method
        - replace + with "accumulate" method

## Random Numbers
- software is deterministic so it cannot produce TRUE random numbers
- we can use pseudorandom numbers
    - initialize a PRNG we use a number called a "seed"
- rand() is inherited from C and declared in <cstdlib>
    - a little arithmetic we can get a random number of a certain range
    - to seed generator used by rand(), we call srand()
        - traditionally, programmers use the current time to seed the generator
- Modern C++ random numbers
    - introduces classes defined in <random>
    - "random number engine" is implemented as a functor
        - default_random_engine
        - mt19937
            - very fast at generating numbers
            - almost crypto secure
            - slow to initialize
    - "distribution" is also implemented as a functor
        - takes the range as arguments
        - good for statistic functions
        - Bernoulli, Normal, Poisson
    - random_device produceds hardware-generated random number from system entropy data
        - much slower than mt19937 but is crypto secure if fully implemented
    - best to use mt19937 as your random number engine
- Random Number algorithms
    - shuffle() rearranges an iterator range in a random order
    - takes a random number engine as an argument to randomize the shuffle
    - std::bernoulli_distribution
        - rescales a sequence of numbers into boolean values

 