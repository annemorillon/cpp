# CPP Modules

Complete C++ learning path from 42 School: 10 modules covering namespaces, memory, polymorphism, inheritance, exceptions, templates, and STL.

---

## Modules Overview

| Module | Topics | Key Concepts |
|--------|-------|-----------|
| **00** | Namespaces, slots, memory allocation, lists | Basic classes, PhoneBook, Account |
| **01** | Memory allocation, pointers, references | Zombie, HumanA/B, Harl, Sed |
| **02** | Ad-hoc polymorphism, operator overloading | Fixed-point, BSP, Orthodox Canonical Form |
| **03** | Inheritance | ClapTrap, ScavTrap, FragTrap, DiamondTrap |
| **04** | Subtype polymorphism, abstract classes | Animal, Brain, Materia, Character |
| **05** | Repetition and Exceptions | Bureaucrat, Forms, Intern |
| **06** | Casts | Scalar conversion, Serialization, Type identification |
| **07** | Templates | Whatever, Iter, Array |
| **08** | Templated containers, iterators | easyFind, Span, MutantStack |
| **09** | STL (Standard Template Library) | BitcoinExchange, RPN, PmergeMe |

---

## Quick Start

```bash
git clone https://github.com/[login]/cpp_modules.git
cd cpp_modules

cd cpp00
make && ./program
```

---

## Repository Structure

```
cpp_modules/
├── cpp00/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
│       ├── includes/
│       ├── src/
│       └── Makefile
├── cpp01/ ... cpp09/
├── README.md
└── .gitignore
```

---

## Testing & Compilation

### Per-Module Testing

```bash
cd cpp00
make              # Compile
./program         # Run
make clean        # Clean objects
make fclean       # Clean all
make re           # Rebuild
```

### Memory Leak Detection

```bash
valgrind --leak-check=full --show-leak-kinds=all ./program
```

### Code Quality Check

```bash
norminette src/ includes/
```

---

## Each Module's README

- [CPP00 README](./cpp00/README.md)
- [CPP01 README](./cpp01/README.md)
- [CPP02 README](./cpp02/README.md)
- [CPP03 README](./cpp03/README.md)
- [CPP04 README](./cpp04/README.md)
- [CPP05 README](./cpp05/README.md)
- [CPP06 README](./cpp06/README.md)
- [CPP07 README](./cpp07/README.md)
- [CPP08 README](./cpp08/README.md)
- [CPP09 README](./cpp09/README.md)