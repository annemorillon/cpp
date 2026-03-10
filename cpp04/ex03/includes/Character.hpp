#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "iostream"
# include "../includes/AMateria.hpp"

class Character: public ICharacter
{
	public: 
	
		Character();
		~Character();

		Character(std::string name);
		Character(Character const& copy);

		Character		&operator=(Character const& old);

		std::string const& getName() const;
		void equip(AMateria* materia);
		void unequip(int ids);
		void use(int ids, ICharacter& target);
		AMateria* getMateria(int ids) const;

	protected:
		std::string		_name;
		AMateria*		_inventory[4];
};

#endif