/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:15 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/05 14:19:22 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string line;

	std::cout << std::endl;
	std::cout << "➡️  Welcome in the phonebook ⬅️" << std::endl;
	std::cout << std::endl;
	while (1)
	{
		std::cout << "\e[1;36m" << ">> " << RESET;
		if (!getline(std::cin, line))
			break;
		if (line == "EXIT")
			break;
		else if (line == "ADD")
			phonebook.addContacts();
		else if (line == "SEARCH")
			phonebook.search();
		else
		{
			std::cout << std::endl;
			std::cout << UNDERLINE << "You have the following 3 possible options" << RESET << " :" << std::endl;
			std::cout << std::endl;
			std::cout << " • ADD : add a contact to the phonebook" << std::endl;
			std::cout << " • SEARCH : search and view a contact's information" << std::endl;
			std::cout << " • EXIT : exit and delete the phonebook" << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "🔸 You're out and your contact are lost 🔸" << std::endl;
	std::cout << std::endl;
	return (0);
}
