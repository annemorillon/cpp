/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:18 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/17 09:09:21 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	_nbContact = 0;
	std::cout << GREY << "Constructor phonebook" << "\e[0;37m" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << GREY << "Destructor phonebook" << "\e[0;37m" << std::endl;
}

Contact	PhoneBook::getContacts(int i)
{
	return (_contacts[i]);
}

int	PhoneBook::getNbContact(void)
{
	return (_nbContact);
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
		if (!getline(std::cin, phoneNumber))
			break ;
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
	_nbContact = i;
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

bool	PhoneBook::setContact(int i)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	darkestSecret;

	while (1)
	{
		std::cout << "First Name : ";
		if (!getline(std::cin, firstName))
			return (false);
		if (!firstName.empty() && !isAllSpace(firstName))
			break ;
		std::cerr << ERROR << "Please enter a first name" << RESET << std::endl;
	}
	_contacts[i].setName(firstName);
	while (1)
	{
		std::cout << "Last Name : ";
		if (!getline(std::cin, lastName))
			return (false);
		if (!lastName.empty() && !isAllSpace(lastName))
			break ;
		std::cerr << ERROR << "Please enter a last name" << RESET << std::endl;
	}
	_contacts[i].setLastName(lastName);
	while (1)
	{
		std::cout << "Nickname : ";
		if (!getline(std::cin, nickname))
			return (false);
		if (!lastName.empty() && !isAllSpace(nickname))
			break ;
		std::cerr << ERROR << "Please enter a nickname" << RESET << std::endl;
	}
	_contacts[i].setNickname(nickname);
	setPhoneNumber(_contacts[i]);
	if (_contacts[i].getPhoneNumber().empty())
		return (false);
	while (1)
	{
		std::cout << "Darkest Secret : ";
		if (!getline(std::cin, darkestSecret))
			return (false);
		if (!darkestSecret.empty() && !isAllSpace(darkestSecret))
			break ;
		std::cerr << ERROR << "Please enter a darkest secret" << RESET << std::endl;
	}
	_contacts[i].setDarkestSecret(darkestSecret);
	return (true);
}

bool	PhoneBook::addContacts(void)
{
	int index = 0;

	while (index < NB_CONTACT && !_contacts[index].getName().empty())
		index++;

	if (index == NB_CONTACT)
	{
		for (int i = 0; i < NB_CONTACT - 1; i++)
			_contacts[i] = _contacts[i + 1];
		index = NB_CONTACT - 1;
	}

	if (!this->setContact(index))
		return (false);
	if (_nbContact != NB_CONTACT)
		this->setNbContact(_nbContact + 1);
	std::cerr << "The contact is added to the phonebook" << std::endl;
	return (true);
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

void	PhoneBook::_printPhoneBook(void)
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
	
	for (int i = 0; i < _nbContact; i++)
	{
		std::cout.width(10);
		std::cout << i + 1;
		std::cout << "|";
		std::cout.width(10);
		printBox(_contacts[i].getName());
		std::cout << "|";
		std::cout.width(10);
		printBox(_contacts[i].getLastName());
		std::cout << "|";
		std::cout.width(10);
		printBox(_contacts[i].getNickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::search(void)
{
	std::string	index_str;
	int			index;

	if (_nbContact == 0)
	{
		std::cerr << ERROR << "PhoneBook is empty : add a contact before search" << RESET << std::endl;
		return ;
	}

	_printPhoneBook();

	while(1)
	{
		std::cout << "Selected the index of your contact : ";
		if (!getline(std::cin, index_str))
			break ;
		if (!index_str.empty() && !isAllSpace(index_str) && index_str.length() == 1)
		{
			index = index_str[0] - '0';
			if (index >= 1 && index <= _nbContact)
			{
				_contacts[index - 1].printContact();
				break ;
			}
		}
		std::cerr << ERROR << "Please enter a valid index" << RESET << std::endl;
	}
}
