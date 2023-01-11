/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:55:32 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 06:42:30 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal")
{
	std::cout << "[AAnimal default constructor has been called!]" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal destructor has been called!]" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "[AAnimal constructor has been called !]" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
	*this = rhs;
	std::cout << "[AAnimal copy constructor has been called !]" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &rhs)
{
	std::cout << "{AAnimal assignement operator has been called}" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "{AAnimal makeSound() has been called}" << std::endl;
}