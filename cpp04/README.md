# CPP05 - Repetition and Exceptions

Exception handling with Bureaucrat system. Forms require signatures and execution with grade validation.

---

## Topics

- Try/catch/throw
- Custom exception classes
- Exception hierarchy
- Grade validation
- Form signing and execution chains
- Intern factory pattern

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
| ex00 | Mommy, when I grow up, I want to be a Bureaucrat! | Bureaucrat class with grade validation |
| ex01 | Form please, sign here... | Form class, signing mechanism |
| ex02 | No, you need form 28B, not 28C... | ShrubberyCreation, Robotomy, Presidential forms |
| ex03 | At least this beats coffee-making | Intern form factory |

---

## Exception Pattern

```cpp
class GradeTooHighException : public std::exception {
public:
	virtual const char* what() const throw() {
		return ("Grade too high");
	}
};

if (grade > 1)
	throw GradeTooHighException();
```

---

## Form Workflow

1. **Create** - Form with sign_grade and exec_grade
2. **Sign** - Bureaucrat signs if grade >= sign_grade
3. **Execute** - Bureaucrat executes if signed & grade >= exec_grade
4. **Exception** - Throw if requirements not met

---

## Form Types

- **ShrubberyCreationForm** - Creates file with ASCII tree
- **RobotomyRequestForm** - 50% success rate robotomy
- **PresidentialPardonForm** - Presidents only

---

## See Also

[Back to CPP Modules](../README.md)