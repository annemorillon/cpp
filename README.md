# CPP Modules

Complete C++ learning path covering fundamentals to advanced features: OOP, STL, templates, exceptions, and design patterns. Each module builds on previous concepts.

---

## Modules Overview

| Module | Topics | Key Concepts |
|--------|--------|--------------|
| **CPP00** | Classes & Objects | Constructors, encapsulation, `operator<<` |
| **CPP01** | Memory & References | Pointers, `new`/`delete`, file I/O, string streams |
| **CPP02** | Inheritance & Polymorphism | Virtual functions, abstract classes, access modifiers |
| **CPP03** | Templates | Generic functions/classes, specialization |
| **CPP04** | Exceptions | Try/catch/throw, custom exceptions, RAII |
| **CPP05** | STL Containers & Algorithms | `vector`, `map`, `list`, iterators, lambdas |
| **CPP06** | C++ Casts | `static_cast`, `dynamic_cast`, `const_cast` |
| **CPP07** | Advanced Templates | Variadic templates, fold expressions, metaprogramming |
| **CPP08** | Templated Containers & Iterators | Custom containers, iterator patterns, generic algorithms |
| **CPP09** | Real-World Applications | RPN calculator, sorting algorithms, design patterns |

---

## Quick Start

```bash
git clone git@github.com:annemorillon/cpp.git
cd cpp_modules

# Build specific module
cd cpp00
make

# Run
./program
```

---

## Repository Structure

```
cpp_modules/
├── cpp00/
│   ├── ex00/
│   ├── ex01/main.cpp
│        ├── includes/
│        ├── src/
│        └── Makefile   
│   ├── ex02/
│   ├── ex03/
├── cpp01/
│   ├── ex00/ ... ex06/
├── cpp02/
├── cpp03/
├── cpp04/
├── cpp05/
├── cpp06/
├── cpp07/
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
