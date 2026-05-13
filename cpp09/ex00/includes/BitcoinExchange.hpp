#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include	<iostream>
# include	<fstream>
# include	<sstream>
# include	<string>
# include	<algorithm>
# include	<map>
# include	<filesystem>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class BitcoinExchange {
	public :

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange &operator=(const BitcoinExchange& other);

		bool	setInfo();

		bool	checkLine(std::string& line);
		void	parsingFile(char *file);

		void	findExchange(std::string date, float value);

	private :
		std::map<std::string, float> _info;
};

#endif