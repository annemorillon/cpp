#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include	<iostream>
# include	<fstream>
# include	<sstream>
# include	<string>
# include	<algorithm>
# include	<map>

class BitcoinExchange {
	public :

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange &operator=(const BitcoinExchange& other);

		bool	checkLine(std::string& line);
		void	parsingFile(std::string& file);

		void	findExchange(std::string date, std::string value);

	private :
		std::map<std::string, std::string> _info;
};

#endif