#ifndef CURE_HPP
# define CURE_HPP

# include "iostream"

class Cure
{
	public: 
	
		Cure(std::string const & type);
		
		std::string const	getType() const;

		virtual Cure* clone() const;

	protected:
		

};

#endif