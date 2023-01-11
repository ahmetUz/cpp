/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:55:32 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 06:42:30 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "[Animal default constructor has been called!]" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal destructor has been called!]" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "[Animal constructor has been called !]" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	*this = rhs;
	std::cout << "[Animal copy constructor has been called !]" << std::endl;
}

Animal&	Animal::operator=(const Animal &rhs)
{
	std::cout << "{Animal assignement operator has been called}" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "{Animal makeSound() has been called}" << std::endl;
}