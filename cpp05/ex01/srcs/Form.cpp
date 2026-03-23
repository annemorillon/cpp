#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{}
Form::~Form()
{}
Form::Form(const std::string name, const int gradetoexecute, const int gradetosign): _name(name), _signed(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute)
{
	if (gradetoexecute < 1 || gradetosign < 1)
		throw GradeTooHighException();
	else if (gradetoexecute > 150 || gradetosign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

Form &Form::operator=(const Form& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getSigned() const
{
	return (_signed);
}

int			Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int			Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void		Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("the grade is too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("the grade is too low !");
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
	os	<< "name : " << form.getName()
		<< "\nsigned : " << form.getSigned()
		<< "\ngradeToSign : " << form.getGradeToSign()
		<< "\ngradeToExecute : " << form.getGradeToExecute() << std::endl;
	return (os);
}