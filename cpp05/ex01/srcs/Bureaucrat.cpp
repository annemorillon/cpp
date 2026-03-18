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
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
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
		_grade = old._grade;
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
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
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

void		Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << '\n';
	}
}