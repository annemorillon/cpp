#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string> 

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Zombie
{
	public:

		Zombie(void);
		~Zombie();
		
		void announce(void);
		void setName(std::string name);

	private:

		std::string	_name;

};

Zombie* zombieHorde(int N, std::string name);

#endif