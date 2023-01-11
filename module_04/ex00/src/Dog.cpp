/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:13:54 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 13:40:08 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "[Dog contructor has been called]" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "[Dog destructor has been called]" << std::endl;
}

Dog::Dog(const Dog &rhs): Animal(rhs)
{
	std::cout << "[Dog copy constructor has been called !]" << std::endl;
}

Dog&	Dog::operator=(const Dog &rhs)
{
	std::cout << "{Dog assignement operator has been called}" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return (*this);
}


void	Dog::makeSound(void) const
{
	std::cout << "WOAF !" << std::endl;
}
