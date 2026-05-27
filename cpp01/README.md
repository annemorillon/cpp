# CPP01 - Memory allocation, pointers to members, references

Memory management in C++: pointers, references, dynamic allocation, and file manipulation.

---

## Topics

- Pointers and references
- Dynamic allocation (`new`/`delete`)
- Pointers to members
- File I/O operations
- String manipulation
- Switch statements

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
| ex00 | BraiiiiiiinnnzzzZ | Zombie class, memory management |
| ex01 | Moar brainz | ZombieHorde, array of objects |
| ex02 | HI THIS IS BRAIN | Pointers and references comparison |
| ex03 | Unnecessary violence | Weapon, HumanA, HumanB |
| ex04 | Sed is for losers | File replacement program |
| ex05 | Harl 2.0 | Logging system |
| ex06 | Harl filter | Filtering output by level |

---

## Key Concepts

1. **Pointers** - Access objects indirectly, can be null, reassigned
2. **References** - Alias to existing object, must be initialized, no null
3. **new/delete** - Dynamic memory allocation and deallocation
4. **Member pointers** - Pointers as class members
5. **File I/O** - Reading and writing files with streams

---

## Memory Safety

Always delete what you new:

```cpp
std::string* ptr = new std::string("hello");
delete ptr;
ptr = nullptr;
```

---

## See Also

[Back to CPP Modules](../README.md)