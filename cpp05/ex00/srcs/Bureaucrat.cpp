#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
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