/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:19:41 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 13:40:35 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat contructor has been called]" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat destructor has been called]" << std::endl;
}

Cat::Cat(const Cat &rhs): Animal(rhs)
{
	std::cout << "[Cat copy constructor has been called !]" << std::endl;
}

Cat&	Cat::operator=(const Cat &rhs)
{
	std::cout << "{Cat assignement operator has been called}" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAW !" << std::endl;
}