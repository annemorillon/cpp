#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{}
AForm::~AForm()
{}
AForm::AForm(const std::string name, const int gradetoexecute, const int gradetosign)
	: _name(name), _signed(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute)
{
	if (gradetoexecute < 1 || gradetosign < 1)
	{
		std::cout << "Error: the grade doesn't exit: ";
		throw GradeTooHighException();
	}
	else if (gradetoexecute > 150 || gradetosign > 150)
	{
		std::cout << "Error: the grade doesn't exit: ";
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm &AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return (_name);
}

bool		AForm::getSigned() const
{
	return (_signed);
}

int			AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int			AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void		AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("the grade is too high !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("the grade is too low !");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return("the form isn't sign !");
}

std::ostream& operator<<(std::ostream& os, AForm& AForm)
{
	os	<< "name : " << AForm.getName()
		<< "\nsigned : " << AForm.getSigned()
		<< "\ngradeToSign : " << AForm.getGradeToSign()
		<< "\ngradeToExecute : " << AForm.getGradeToExecute() << std::endl;
	return (os);
}