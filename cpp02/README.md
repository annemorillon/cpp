# CPP02 - Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form

Master operator overloading with fixed-point numbers and binary space partitioning. Learn Orthodox Canonical Form.

---

## Topics

- Orthodox Canonical Class Form (constructor, copy, assignment, destructor)
- Operator overloading (arithmetic, comparison, stream)
- Fixed-point number representation
- Static members
- Const correctness
- Binary Space Partitioning (BSP)

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
| ex00 | My First Class in Orthodox Canonical Form | Fixed-point class with conversions |
| ex01 | Towards a more useful fixed-point number | Arithmetic operators |
| ex02 | Now we're talking | Comparison and stream operators |
| ex03 | BSP | Point in triangle test |

---

## Orthodox Canonical Form

A complete class should have:

```cpp
class Fixed {
public:
	Fixed();                            // Default constructor
	Fixed(const Fixed& other);          // Copy constructor
	Fixed& operator=(const Fixed& rhs); // Copy assignment
	~Fixed();                           // Destructor
};
```

---

## Fixed-Point Representation

```cpp
// Fixed point: value * 2^8 (256)
// 10.5 stored as: 10.5 * 256 = 2688
int _fixed_value;
static const int _fractional_bits = 8;
```

---

## See Also

[Back to CPP Modules](../README.md)