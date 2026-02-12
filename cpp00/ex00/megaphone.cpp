/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:21:41 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/12 11:21:42 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout  << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string	txt[argc - 1];

		for(int i = 0; i < argc - 1; ++i)
			txt[i] = static_cast<std::string>(argv[i + 1]);
		
		for(int i = 0; i < argc - 1; ++i)
		{
			for(long unsigned int j = 0; j < txt[i].length(); j++)
				txt[i][j] = toupper(txt[i][j]);
		}

		for(int i = 0; i < argc - 2; ++i)
			std::cout  << txt[i] << " ";
		std::cout << txt[argc - 2];
		std::cout << std::endl;
	}
	return (0);
}