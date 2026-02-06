/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:22 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/05 14:14:05 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "../includes/contact.hpp"

class PhoneBook
{
	public :

		PhoneBook(void);
		~PhoneBook();

		Contact	getContacts(int i);
		int		getNbContact(void);

		void	setContact(int i);
		void	setNbContact(int i);
		
		void	addContacts(void);
		void	search(void);
	
	private :

		int		nbContact;
		Contact contacts[8];
		
		void	printContact(int i);
		void	printPhoneBook(void);

};

#endif