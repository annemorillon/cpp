#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static bool	_robotomy = false;

RobotomyRequestForm::RobotomyRequestForm(): AForm(), _target("Default")
{}
RobotomyRequestForm::~RobotomyRequestForm()
{}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 45, 72), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void		RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (_robotomy == false)
	{
		_robotomy = true;
		std::cout	<< "fffff... the robotomy failed !" << std::endl;
	}
	else
	{
		_robotomy = false;
		std::cout	<< "fffff..." << _target << " has been robotomiwed successfully 50% of the time !" << std::endl;
	}
}
