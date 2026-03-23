#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "iostream"
# include "AForm.hpp"

class RobotomyRequestForm: virtual public AForm
{
	public:

		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

		void		execute(Bureaucrat const& executor) const;
		void		printExecute();

	private:

		std::string	_target;

};

#endif