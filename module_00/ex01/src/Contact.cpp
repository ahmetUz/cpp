/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:37:03 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 17:37:15 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::get_input(std::string str)
{
	std::string	buf = "";
	bool		valid = false;

	if (std::cin.fail())
		return (buf);
	while (!valid)
	{
		std::cout << str;
		std::getline(std::cin, buf);
		if (std::cin.good() && !buf.empty())
		{
			std::cout << std::endl;
			valid = true;
		}
		else
		{
			if (std::cin.fail())
				return (buf);
			std::cin.clear();
			std::cout << "Invalid input retry!" << std::endl;
		}
	}
	return (buf);
}


void	Contact::set_atr(int index)
{
	this->index = index;
	this->first_name = this->get_input("Enter your first name: ");
	this->last_name = this->get_input("Enter your last name: ");
	this->nickname = this->get_input("Enter your nickname: ");
	this->phone_number = this->get_input("Enter your phone number: ");
	this->secret = this->get_input("Enter your darkest secret: ");
}
