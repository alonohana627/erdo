# erdo
## My own C++ Adventures

This project doesn't really have any porpuse other than knowing better C++. Why? because C++ is complex, intriguing, bizzare and obscure. I love system programming. I love C.
C is simple, relaxed, and if you follow few rules your life will be easy. C++ is not.

## Examples for C++ bizzare traits
These traits are NOT C++ exclusive per-se but they are bloated out of the earth by C++:
- Rule of Five
- RAII and weird memory management.
- Template Metaprogramming
- Weird naming.
- `constexpr`, `consteval`, `constinit`, `const`.
- Verbosity that makes C code looks short.
- Annoying debugging.

## Parts:
For now Im working on the math an specifically on the Linear Algebra part. The reason is that I don't know Linear Algebra and that it is easy to construct a structure of how your code should be when our code relates to Linear Algebra.

### Math

#### General
- TODO: General easy-to-do functions such as: `average`, `factorial`, `fibonacci`, `absolute`, `floor`, `ceil`.
- TODO: Tests for each

##### Rational Number
The goal is to have a class that acts as if C++ has Rational Number, including tests. I don't know if anyone besides me will ever inspect this code, but if you think something is not complete create an issue or message me.

#### Linear Algebra
##### **Vector** 
Should act as a mathematical vector. Using a `std::vector` behind the scene, until I will make my own `container` library.

**TODO**:
- Zero Vector constructor.
- Constant size.
- Scalar multiplication
- Vector addition and substruction

##### **Matrix**
Not "operated" yet. WIll use the `erdo::Vector` class.

**TODO**:
- Zero Matrix
- Spare Matrix
- Identity Matrix
- Square Matrix
- Operations (Addition, Multiplication, Substruction)
- Constructors (ALOT OF THEM)
- Bound checking

### Containers

In the future I hope I will do:
- `erdo::Iterator`.
- `erdo::Container`.
- `erdo::Hash`, `erdo::HashMap`.
- `erdo::Stack`, `erdo::Queue`, `erdo::LinkedList`, `erdo::DynamicArray`.
