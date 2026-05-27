# CPP08 - Templated containers, iterators, algorithms

Build custom containers and master iterator patterns. Implement easyFind, Span, and MutantStack.

---

## Topics

- Generic algorithms
- Custom containers
- Iterator implementation
- Container adapters
- Bounds checking
- Exception safety

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
| ex00 | Easy find | Find element in any container using template |
| ex01 | Span | Fixed-size container with span calculations |
| ex02 | MutantStack | Stack with iterator support |

---

## Containers

### easyFind
- Template function
- Works with any container
- Uses `std::find()`
- Throws if not found

### Span
- Fixed-size container
- Store up to N elements
- Methods: shortestSpan(), longestSpan()
- Bounds checking

### MutantStack
- Inherits from `std::stack<T>`
- Adds iterator support (begin(), end())
- Allows range-based algorithms
- Combines stack behavior with iteration

---

## easyFind Pattern

```cpp
template<typename T, typename Container>
typename Container::iterator easyFind(Container& c, T value)
{
	auto it = std::find(c.begin(), c.end(), value);
	if (it == c.end())
		throw std::exception();
	return (it);
}
```

---

## MutantStack Pattern

```cpp
template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};
```

---

## See Also

[Back to CPP Modules](../README.md)