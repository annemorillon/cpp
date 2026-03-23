#ifndef INTERN_HPP
# define INTERN_HPP

class AForm;
# include "iostream"

class Intern
{
	public:

		Intern();
		~Intern();
		Intern(Intern const& other);
		Intern& operator=(Intern const& other);

		AForm*	makeForm(std::string name, std::string target);

};

#endif