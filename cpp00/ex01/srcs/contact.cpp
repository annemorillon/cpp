/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:09 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/17 08:54:05 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"

Contact::Contact(void)
{
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_phoneNumber = "";
	_darkestSecret = "";
	std::cout << GREY << "Constructor contact" << RESET << std::endl;
}

Contact::~Contact()
{
	std::cout << GREY << "Destructor contact" << RESET << std::endl;
}

std::string	Contact::getName() const
{
	return (_firstName);
}

void	Contact::setName(std::string newName)
{
	_firstName = newName;
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

void	Contact::setLastName(std::string newLastName)
{
	_lastName = newLastName;
}

std::string	Contact::getNickname(void) const
{
	return (_nickname);
}

void	Contact::setNickname(std::string newNickname)
{
	_nickname = newNickname;
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

void	Contact::setPhoneNumber(std::string newPhoneNumber)
{
	_phoneNumber = newPhoneNumber;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

void	Contact::setDarkestSecret(std::string newDarkestSecret)
{
	_darkestSecret = newDarkestSecret;
}

void	Contact::printContact(void) const
{
	std::cout << "First Name : " << _firstName << std::endl;
	std::cout << "Last Name : " << _lastName << std::endl;
	std::cout << "Nick Name : " << _nickname << std::endl;
	std::cout << "Phone Number : " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret : " << _darkestSecret << std::endl;
}