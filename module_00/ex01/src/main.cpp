/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:12:02 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 22:57:51 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	pb;
	std::string	input;

	pb.set_nb_contact(0);
	while (input != "EXIT")
	{
		input.clear();
		std::cout << "PhoneBook> ";
		std::cin >> std::ws;
		if (!std::getline(std::cin, input) || std::cin.fail())
			return (std::cout << std::endl, -1);
		if (input == "ADD")
			pb.add_contact();
		else if (input == "SEARCH")
		{
			pb.view_contacts();
			pb.search();
		}
		if (std::cin.fail())
			return (std::cout << std::endl, -1);
	}
	return (0);
}