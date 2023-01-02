/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:24:12 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 22:14:50 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::set_nb_contact(int nb)
{
	this->nb_contacts = nb;
}

int	PhoneBook::get_nb_contact() const
{
	return (this->nb_contacts);
}

void	PhoneBook::add_contact(void)
{
	static int	index;
	this->contacts[index % 8].set_atr(index);
	this->set_nb_contact((this->get_nb_contact() + 1) % 8);
	index++;
}

void	PhoneBook::view_contacts(void) const
{
	std::cout << "---------------CONTACTS-----------------" << std::endl;
	for (size_t i = 0; i < 8; i++)
		this->contacts[i].view();
	std::cout << std::endl;
}

int	PhoneBook::get_index() const
{
	bool	valid = false;
	int		index = -1;

	if (std::cin.fail())
		return (-1);
	while (!valid)
	{
		std::cout << "Give the contact's index: ";
		std::cin >> index;
		if (std::cin.good() && (index >= 0 && index <= 7)
			&& index < this->get_nb_contact())
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index retry!" << std::endl;
		}
	}
	return (index);
}

void	PhoneBook::search(void) const
{
	if (this->get_nb_contact() == 0)
	{
		std::cout << "There is no contact yet! " << std::endl;
		return ;
	}
	int	index = this->get_index();
	if (index < 0)
		return ;
	this->contacts[index].display();
}