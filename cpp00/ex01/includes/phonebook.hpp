/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:09:22 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/17 09:08:49 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "../includes/contact.hpp"

# define NB_CONTACT	8

class PhoneBook
{
	public :

		PhoneBook(void);
		~PhoneBook();

		Contact	getContacts(int i);
		int		getNbContact(void);

		bool	setContact(int i);
		void	setNbContact(int i);
		
		bool	addContacts(void);
		void	search(void);
	
	private :

		int		_nbContact;
		Contact _contacts[NB_CONTACT];
		
		void	_printPhoneBook(void);

};

#endif