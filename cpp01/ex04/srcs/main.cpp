#include "../includes/header.hpp"

static bool	openAndCopyFile(char *file, std::string& txt)
{
	std::string	line;

	std::ifstream fileIn;

	fileIn.open(file);
	if (!fileIn)
	{
		std::cerr << "Error: open fileIn" << std::endl;
		return (false);
	}
	while (1)
	{
		txt += line;
		if (!getline(fileIn, line))
			break;
		else
			txt += '\n';
	}
	fileIn.close();
	return (true);
}

static void find_and_replace(std::string& txt, std::string s1, std::string s2)
{
	std::string	tmp;
	size_t	startS1 = 0;
	
	while (1)
	{
		startS1 = txt.find(s1, 0);
		if (startS1 > txt.length())
			break;
		tmp = txt.substr(0, startS1) + s2 + txt.substr(startS1 + s1.length());
		txt = tmp;
	}
}

int main(int argc, char **argv)
{
	std::string		txt;
	std::string		s1;
	std::string		s2;
	std::string		name;
	std::ofstream	fileOut;

	if (argc != 4)
	{
		std::cerr << "Usage: [./readfile file s1 s2]" << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: the string to be replaced must already exist" << std::endl;
		return (1);
	}
	if (!openAndCopyFile(argv[1], txt))
		return (1);
	find_and_replace(txt, s1, s2);
	name = argv[1];
	name += ".replace";
	fileOut.open(name.c_str());
	if (!fileOut)
	{
		std::cerr << "Error: open fileOut" << std::endl;
		return (false);
	}
	fileOut << txt << std::endl;
	fileOut.close();
	return (0);
}