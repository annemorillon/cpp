# CPP03 - Inheritance

Build class hierarchies with ClapTrap and variants. Master single and multiple inheritance.

---

## Topics

- Single inheritance
- Multiple inheritance
- Protected access level
- Constructor chains
- Method overriding
- Diamond problem

---

## Quick Start

```bash
make
./program
```

---

## Exercises

| Exercise | Title | Class | Description |
|----------|-------|-------|-------------|
| ex00 | Aaaaand... OPEN! | ClapTrap | Base class with hit points, energy, attack |
| ex01 | Serena, my love! | ScavTrap | Inherits ClapTrap, guardGate() special ability |
| ex02 | Repetitive work | FragTrap | Inherits ClapTrap, highFivesGuys() special ability |
| ex03 | Now it's weird | DiamondTrap | Multiple inheritance from ScavTrap & FragTrap |

---

## Class Hierarchy

```
ClapTrap (base class)
├── ScavTrap (public inheritance)
├── FragTrap (public inheritance)
└── DiamondTrap (multi-level: ScavTrap + FragTrap)
```

---

## Basic Inheritance Pattern

```cpp
class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	void guardGate();
	void attack(std::string target);  // Override
};
```

---

## Diamond Problem

DiamondTrap inherits from both ScavTrap and FragTrap, which both inherit from ClapTrap. Resolve ambiguity with proper virtual inheritance or scope resolution.

---

## See Also

[Back to CPP Modules](../README.md)