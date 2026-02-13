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

		void announce (void);
		Zombie* newZombie(std::string name);
		void randomChump(std::string name);

	private:

		std::string	name;

}

#endif