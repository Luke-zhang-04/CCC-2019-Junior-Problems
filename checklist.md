# Competitive Programming Checklist
Note that it is a better idea to focus on optimizations within loops and recursive functions, since those smaller slowdowns add up a lot

- Can I use previously computed values in my loop?
- If I'm comparing large strings, can I hash them to save memory?
- Can I move my loop inside a function call a function in a loop?


## C++ Specific
- Can I used unordered versions of what I am using right now?
- Can I avoid types such as floats?
- Can I pass in values by reference?
See [https://people.cs.clemson.edu/~dhouse/courses/405/papers/optimize.pdf](https://people.cs.clemson.edu/~dhouse/courses/405/papers/optimize.pdf)

## Python Specific
- Can I use built-ins to speed up my program such as `map`
- Can I avoid accessing a method in a loop by referencing the method to a variable in the upper scope?
See [https://wiki.python.org/moin/PythonSpeed/PerformanceTips](https://wiki.python.org/moin/PythonSpeed/PerformanceTips)
