#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "iostream"
# include "AForm.hpp"

class PresidentialPardonForm: virtual public AForm
{
	public:

		PresidentialPardonForm();
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);

		void		execute(Bureaucrat const& executor) const;

	private:

		std::string	_target;

};

#endif