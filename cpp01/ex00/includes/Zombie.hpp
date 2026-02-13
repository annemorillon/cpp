#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string> 

# define RESET		"\e[0;37m"
# define GREY		"\e[2;37m"

class Zombie
{
	public:

		Zombie(std::string name);
		~Zombie();
		
		void announce(void);

	private:

		std::string	_name;

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif