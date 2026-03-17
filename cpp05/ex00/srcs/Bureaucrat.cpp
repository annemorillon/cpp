#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	// std::cout << GREY "Bureaucrat default constructor called " RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << GREY "Bureaucrat destructor called " RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	try
	{
		if (grade < 1)
		{
			_grade = 1;
			throw GradeTooHighException();
		}
		else if (grade > 150)
		{
			_grade = 150;
			throw GradeTooLowException();
		}
		else
			_grade = grade;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// std::cout << GREY "Bureaucrat constructor called " RESET << std::endl;	
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
	// std::cout << GREY "Bureaucrat constructor copy called " RESET << std::endl;	
	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const& old)
{
	if (this != &old)
	{
		_grade = old._grade;
	}
	return (*this);
}

std::string const	Bureaucrat::getName() const
{
	return (_name);
}

int					Bureaucrat::getGrade() const
{
	return (_grade);
}

void				Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void				Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade >= 150)
			throw GradeTooLowException();
		else
			_grade++;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error: the grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Error: the grade is too low !");
}