#ifndef SCHRUBBERYCREATIONFORM_HPP
# define SCHRUBBERYCREATIONFORM_HPP

# include "iostream"
# include "AForm.hpp"

class SchrubberyCreationForm: virtual public AForm
{
	public:

		SchrubberyCreationForm();
		virtual ~SchrubberyCreationForm();

		SchrubberyCreationForm(const std::string& target);
		SchrubberyCreationForm(const SchrubberyCreationForm& other);
		SchrubberyCreationForm &operator=(const SchrubberyCreationForm& other);

		void		execute(Bureaucrat const& executor) const;

	private:

		std::string	_target;

};

#endif