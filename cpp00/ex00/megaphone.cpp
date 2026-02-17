/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmorill <anmorill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:21:41 by anmorill          #+#    #+#             */
/*   Updated: 2026/02/17 08:42:45 by anmorill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	int nb_word = argc;

	for(int i = 1; i < argc; i++)
	{
		if (!argv[i][0])
			nb_word--;
		for(long unsigned int j = 0; argv[i][j]; j++)
		{
			argv[i][j] = toupper(argv[i][j]);
		}
		std::cout << argv[i];
	}

	if (nb_word == 1)
		std::cout  << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << std::endl;
	return (0);
}