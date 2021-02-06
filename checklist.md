# Competitive Programming Checklist
Note that it is a better idea to focus on optimizations within loops and recursive functions, since those smaller slowdowns add up a lot

- Can I use previously computed values in my loop/recursion? (Dynamic programming)
- If I'm comparing large strings, can I hash them to save memory? (note that built in, generic hash functions are very fast)
- Can I move my loop inside a function instead of calling a function in a loop?


## C++ Specific
- Can I used unordered versions of what I am using right now? (E.g `unordered set`, `unordered_map`)
- Can I avoid types such as floats?
- Can I pass in values by referencei instead of by value?
See [https://people.cs.clemson.edu/~dhouse/courses/405/papers/optimize.pdf](https://people.cs.clemson.edu/~dhouse/courses/405/papers/optimize.pdf)

## Python Specific
- Can I use built-ins to speed up my program such as `map` or `dict.setdefault`?
- Can I use a set instead of a list for an faster lookup time?
  - Note that it is faster to iterate over a list, but faster to check if an element is in a set
- Can I avoid passing unecessary function parameters, especially in recursive functions?
- Can I avoid accessing a method in a loop by referencing the method to a variable in the upper scope?
See [https://wiki.python.org/moin/PythonSpeed/PerformanceTips](https://wiki.python.org/moin/PythonSpeed/PerformanceTips)
