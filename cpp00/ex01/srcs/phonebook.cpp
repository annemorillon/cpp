/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:18 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/05 14:07:05 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->nbContact = 0;
	std::cout << GREY << "Constructor phonebook" << "\e[0;37m" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << GREY << "Destructor phonebook" << "\e[0;37m" << std::endl;
}

Contact	PhoneBook::getContacts(int i)
{
	return (this->contacts[i]);
}

int	PhoneBook::getNbContact(void)
{
	return (this->nbContact);
}

static bool	isPhoneNumber(std::string phone_number)
{
	for (int i = 0; i < (int)phone_number.length(); i++)
	{
		if (!isdigit(phone_number[i]))
			return (false);
	}
	return (true);
}

static void	setPhoneNumber(Contact& contact)
{
	std::string	phoneNumber;

	while (1)
	{
		std::cout << "Phone Number : ";
		getline(std::cin, phoneNumber);
		if (isPhoneNumber(phoneNumber))
		{
			contact.setPhoneNumber(phoneNumber);
			break;
		}
		std::cerr << ERROR << "Please enter a valid number" << RESET << std::endl;
	}
}

void	PhoneBook::setNbContact(int i)
{
	this->nbContact = i;
}

static bool	isAllSpace(std::string txt)
{
	size_t i = 0;

	while (i < txt.length() && std::iswspace(txt[i]))
		i++;
	if (i < txt.length())
		return (false);
	return (true);	
}

void	PhoneBook::setContact(int i)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	darkestSecret;


	while (1)
	{
		std::cout << "First Name : ";
		getline(std::cin, firstName);
		if (!firstName.empty() && !isAllSpace(firstName))
			break ;
		std::cerr << ERROR << "Please enter a first name" << RESET << std::endl;
	}
	this->contacts[i].setName(firstName);
	while (1)
	{
		std::cout << "Last Name : ";
		getline(std::cin, lastName);
		if (!lastName.empty() && !isAllSpace(lastName))
			break ;
		std::cerr << ERROR << "Please enter a last name" << RESET << std::endl;
	}
	this->contacts[i].setLastName(lastName);
	while (1)
	{
		std::cout << "Nickname : ";
		getline(std::cin, nickname);
		if (!lastName.empty() && !isAllSpace(nickname))
			break ;
		std::cerr << ERROR << "Please enter a nickname" << RESET << std::endl;
	}
	this->contacts[i].setNickname(nickname);
	setPhoneNumber(this->contacts[i]);
	while (1)
	{
		std::cout << "Darkest Secret : ";
		getline(std::cin, darkestSecret);
		if (!darkestSecret.empty() && !isAllSpace(darkestSecret))
			break ;
		std::cerr << ERROR << "Please enter a darkest secret" << RESET << std::endl;
	}
	this->contacts[i].setDarkestSecret(darkestSecret);
}

void	PhoneBook::addContacts(void)
{
	int index = 0;

	while (index < 8 && !this->contacts[index].getName().empty())
		index++;

	if (index == 8)
	{
		for (int i = 0; i < 7; i++)
			this->contacts[i] = this->contacts[i + 1];
		index = 7;
	}

	this->setContact(index);
	if (this->nbContact != 8)
		this->setNbContact(this->nbContact + 1);
	std::cerr << "The contact is added to the phonebook" << std::endl;
}

static void	printBox(std::string txt)
{
	if (txt.empty())
		return ;
	else if (txt.length() > 10)
		std::cout << txt.substr(0,9) + ".";
	else
		std::cout << txt;
}

void	PhoneBook::printPhoneBook(void)
{
	std::cout.width(10);
	std::cout << "index";
	std::cout << "|";
	std::cout.width(10);
	std::cout << "first name";
	std::cout << "|";
	std::cout.width(10);
	std::cout << "last name";
	std::cout << "|";
	std::cout.width(10);
	std::cout << "nick name";
	std::cout << std::endl;
	
	for (int i = 0; i < this->nbContact; i++)
	{
		std::cout.width(10);
		std::cout << i + 1;
		std::cout << "|";
		std::cout.width(10);
		printBox(this->contacts[i].getName());
		std::cout << "|";
		std::cout.width(10);
		printBox(this->contacts[i].getLastName());
		std::cout << "|";
		std::cout.width(10);
		printBox(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::printContact(int i)
{
	std::cout << "First Name : " << this->contacts[i].getName() << std::endl;
	std::cout << "Last Name : " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nick Name : " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone Number : " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << this->contacts[i].getDarkestSecret() << std::endl;
}

void	PhoneBook::search(void)
{
	std::string	index_str;
	int			index;

	if (this->nbContact == 0)
	{
		std::cerr << ERROR << "PhoneBook is empty : add a contact before search" << RESET << std::endl;
		return ;
	}

	this->printPhoneBook();

	while(1)
	{
		std::cout << "Selected the index of your contact : ";
		if (!getline(std::cin, index_str))
			break ;
		if (!index_str.empty() && !isAllSpace(index_str) && index_str.length() == 1)
		{
			index = index_str[0] - '0';
			if (index >= 1 && index <= this->nbContact)
			{
				printContact(index - 1);
				break ;
			}
		}
		std::cerr << ERROR << "Please enter a valid index" << RESET << std::endl;
	}
}
