/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:15 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/17 09:05:02 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

void	print_action(void)
{
	std::cout << std::endl << UNDERLINE << "You have the following 3 possible options" << RESET << " :" << std::endl;
	std::cout << std::endl;
	std::cout << " • ADD : add a contact to the phonebook" << std::endl;
	std::cout << " • SEARCH : search and view a contact's information" << std::endl;
	std::cout << " • EXIT : exit and delete the phonebook" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	PhoneBook phonebook;
	std::string line;

	std::cout << std::endl << "➡️  Welcome in the phonebook ⬅️" << std::endl;
	print_action();
	while (1)
	{
		std::cout << "\e[1;36m" << ">> " << RESET;
		if (!getline(std::cin, line))
			break;
		if (line == "EXIT")
			break;
		else if (line == "ADD")
		{
			if (!phonebook.addContacts())
				break;
		}
		else if (line == "SEARCH")
			phonebook.search();
		else
			print_action();
	}
	std::cout << std::endl;
	std::cout << "🔸 You're out and your contact are lost 🔸" << std::endl;
	std::cout << std::endl;
	return (0);
}
