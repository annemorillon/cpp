# CPP07 - Templates

Generic programming with function and class templates. Write min, max, swap, and a generic Array class.

---

## Topics

- Function templates
- Class templates
- Template instantiation
- Template specialization
- Generic algorithms
- Container patterns

---

## Quick Start

```bash
make
./program
```

---

## Exercises

| Exercise | Title | Description |
|----------|-------|-------------|
| ex00 | Start with a few functions | whatever<T>, min<T>, max<T>, swap<T> |
| ex01 | Iter | Iterate function with callable |
| ex02 | Array | Generic Array<T> template class |

---

## Key Concepts

1. **Template Declaration** - `template<typename T>`
2. **Type Parameter** - T can be any type
3. **Implementation in Header** - Templates need visibility at compile time
4. **Instantiation** - Compiler generates code for used types
5. **Specialization** - Override template for specific types

---

## Function Template Pattern

```cpp
template<typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

// Automatic instantiation
int x = min(5, 3);           // T = int
double y = min(3.14, 2.71);  // T = double
```

---

## Class Template Pattern

```cpp
template<typename T>
class Array {
private:
	T* _data;
	unsigned int _size;
public:
	Array(unsigned int n);
	T& operator[](unsigned int i);
	unsigned int size() const;
};
```

---

## Template Implementation Rule

Templates require implementation visible at compile time:

```cpp
// In Array.hpp
#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array { /* declaration */ };

#include "Array.cpp"  // Include implementation

#endif
```

---

## See Also

[Back to CPP Modules](../README.md)