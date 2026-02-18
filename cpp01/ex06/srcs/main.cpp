#include "../includes/harl.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
	Harl harl;

	(void) argc;
	switch(argv[1][0])
	{
		case 'D':
			harl.complain("DEBUG");
		case 'I':
			harl.complain("INFO");
		case 'W':
			harl.complain("WARNING");
		case 'E':
			harl.complain("ERROR");
	}
	return (0);
}
