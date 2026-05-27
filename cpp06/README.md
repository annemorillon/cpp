# CPP06 - Casts

Master type conversions and casting in C++. Implement scalar conversions, serialization, and type identification.

---

## Topics

- `static_cast`
- `dynamic_cast`
- `const_cast`
- `reinterpret_cast`
- Scalar type conversion
- Serialization/deserialization
- Type identification (RTTI)

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
| ex00 | Scalar conversion | Convert string to int, float, double, char |
| ex01 | Serialization | Convert pointer to uintptr_t and back |
| ex02 | Identify real type | Determine actual type of polymorphic object |

---

## Cast Types

| Cast | Purpose | Safety |
|------|---------|--------|
| `static_cast<T>(x)` | Explicit conversions checked by compiler | ⚠️ Can lose data |
| `dynamic_cast<T*>(p)` | Polymorphic downcast with runtime check | ✅ Safe |
| `const_cast<T>(x)` | Add/remove const or volatile | ⚠️⚠️ Dangerous |
| `reinterpret_cast<T>(x)` | Low-level bitwise conversion | ⚠️⚠️⚠️ UB risk |

---

## Safe dynamic_cast

```cpp
Base* ptr = new Derived();
if (Derived* d = dynamic_cast<Derived*>(ptr)) {
	d->derivedMethod();
} else {
	std::cout << "Not a Derived!" << std::endl;
}
```

---

## See Also

[Back to CPP Modules](../README.md)