/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:37:03 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 22:05:23 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::get_input(std::string str) const
{
	std::string	buf;
	bool		valid = false;

	if (std::cin.fail())
		return (buf);
	while (!valid)
	{
		std::cout << str << std::flush;
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

void	Contact::set_index(int index)
{
	this->index = index;
}

void	Contact::set_atr(int index)
{
	this->set_index(index);
	this->first_name = this->get_input("Enter your first name: ");
	this->last_name = this->get_input("Enter your last name: ");
	this->nickname = this->get_input("Enter your nickname: ");
	this->phone_number = this->get_input("Enter your phone number: ");
	this->secret = this->get_input("Enter your darkest secret: ");
}

std::string	Contact::trunc(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::view(void) const
{
	if (this->first_name.empty() || this->last_name.empty() || this->nickname.empty())
		return ; 
	std::cout << "|" << std::setw(10) << this->index << std::flush;
	std::cout << "|" << std::setw(10) << this->trunc(first_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->trunc(last_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->trunc(nickname) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display(void) const
{
	if (this->first_name.empty() || this->last_name.empty() || this->nickname.empty())
		return ;
	std::cout << std::endl;
	std::cout << "FIRST NAME :\t" << this->first_name << std::endl;
	std::cout << "LAST NAME :\t" << this->last_name << std::endl;
	std::cout << "NICKNAME :\t" << this->nickname << std::endl;
	std::cout << "DARKEST SECRET :\t" << this->secret << std::endl;
	std::cout << std::endl;
}