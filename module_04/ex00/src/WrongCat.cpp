/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:39:30 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:44:48 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat contructor has been called]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat copy contructor has been called]" << std::endl;
	*this = rhs;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat destructor has been called]" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MIAW !" << std::endl;
}