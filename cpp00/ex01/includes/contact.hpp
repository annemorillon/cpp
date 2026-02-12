/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:27 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/12 10:27:39 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string> 
# include <bits/stdc++.h>

# define RESET		"\e[0;37m"
# define BOLD		"\e[1;37m"
# define GREY		"\e[2;37m"
# define ERROR		"\e[3;31m"
# define UNDERLINE	"\e[4;37m"

class Contact
{
	public :

		Contact(void);
		~Contact();

		std::string	getName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
		
		void		setName(std::string newName);
		void		setLastName(std::string newLastName);
		void		setNickname(std::string newNickname);
		void		setPhoneNumber(std::string newPhoneNumber);
		void		setDarkestSecret(std::string newDarkestSecret);
	
	private :

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif