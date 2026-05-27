# CPP09 - STL (Standard Template Library)

Capstone module: real-world applications using STL. Bitcoin exchange, RPN calculator, and advanced sorting.

---

## Topics

- CSV parsing and file handling
- Stack-based computation (RPN)
- Sorting optimization (Ford-Johnson)
- Binary search
- STL containers (map, vector, stack)
- Algorithm performance

---

## Quick Start

```bash
make

./btc input.txt
./RPN "8 9 * 9 - 9 - 9 - 4 - 7 + 6 +"
./PmergeMe 5 2 8 1 9
```

---

## Exercises

| Exercise | Program | Difficulty |
|----------|---------|-----------|
| ex00 | Bitcoin Exchange | Medium |
| ex01 | Reverse Polish Notation | Medium |
| ex02 | PmergeMe | Hard |

---

## ex00: Bitcoin Exchange

**Input**: CSV with dates and prices, text file with requests  
**Output**: Date × price for each request

```
2011-01-03 => 3 = 30
2011-01-05 => 2 = 1000.5
```

**Key Concepts**:
- Parse CSV file
- Binary search for price lookup
- Date validation
- Error handling

---

## ex01: RPN (Reverse Polish Notation)

**Input**: String in postfix notation  
**Output**: Result of evaluation

```
8 9 * 9 - 9 - 9 - 4 - 7 + 6 +
→ 42
```

**Key Concepts**:
- Stack for operands
- Parse tokens
- Apply operators (+, -, *, /)
- Single result validation

---

## ex02: PmergeMe (Ford-Johnson Sort)

**Input**: Sequence of numbers  
**Output**: Sorted sequence + performance metrics

```
5 2 8 1 9
1 2 5 8 9
```

**Key Concepts**:
- Ford-Johnson (merge-insert) algorithm
- Use 2 different container types (vector + deque)
- Performance measurement
- Optimal comparison count

---

## See Also

[Back to CPP Modules](../README.md)