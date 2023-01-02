/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:37:03 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 03:28:33 by auzun            ###   ########.fr       */
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
	std::string	buf;

	if (std::cin.fail())
		return (buf);
	std::cout << str;
	std::getline(std::cin, buf);
	std::cout << std::endl;
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
