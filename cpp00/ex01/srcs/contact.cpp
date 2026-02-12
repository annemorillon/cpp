/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:09 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/12 10:28:22 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"

Contact::Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
	std::cout << GREY << "Constructor contact" << RESET << std::endl;
}

Contact::~Contact()
{
	std::cout << GREY << "Destructor contact" << RESET << std::endl;
}

std::string	Contact::getName() const
{
	return (this->firstName);
}

void	Contact::setName(std::string newName)
{
	this->firstName = newName;
}

std::string	Contact::getLastName(void) const
{
	return (this->lastName);
}

void	Contact::setLastName(std::string newLastName)
{
	this->lastName = newLastName;
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

void	Contact::setNickname(std::string newNickname)
{
	this->nickname = newNickname;
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->phoneNumber);
}

void	Contact::setPhoneNumber(std::string newPhoneNumber)
{
	this->phoneNumber = newPhoneNumber;
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->darkestSecret);
}

void	Contact::setDarkestSecret(std::string newDarkestSecret)
{
	this->darkestSecret = newDarkestSecret;
}