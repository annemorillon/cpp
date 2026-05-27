# CPP05 - STL Containers & Algorithms

Standard Template Library: containers, iterators, algorithms, and smart pointers.

---

## Topics

- STL Containers (`vector`, `list`, `map`, `set`)
- Iterators
- STL Algorithms (`sort`, `find`, `transform`)
- Functors & Lambdas
- Smart Pointers

---

## Quick Start

```bash
make
./program
```

---

## Key Containers

| Container | Use Case |
|-----------|----------|
| `vector` | Dynamic array |
| `list` | Linked list |
| `map` | Key-value pairs |
| `set` | Unique elements |

---

## Quick Example

```cpp
std::vector<int> vec = {3, 1, 4};
std::sort(vec.begin(), vec.end());
std::for_each(vec.begin(), vec.end(), 
	[](int n) { std::cout << n << " "; });
```

---

## See Also

[Back to CPP Modules](../README.md)