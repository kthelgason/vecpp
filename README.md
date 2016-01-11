# vecpp
A C++ vector header.

* * *

This is an experiment using the c++ template system to do cool things at compile time.
It contains a small vector class and some member functions. I will be adding support for
more operations soon.

## Usage example

```c++

// Create two vectors of size 3 and 5 respectively, initialized to 0 by default.
auto v1 = Vec<int, 3>();
auto v2 = Vec<int, 5>();

// Set some values
v1.set<0>(1);
v1.set<1>(2);

// Attempting to set a value outside the vector gives a compile-time error.
v1.set<3>(5);

// This will also give a compile-time error as the vectors are of different sizes
auto v3 = v1 + v2;


```
