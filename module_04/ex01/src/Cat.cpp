/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:19:41 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 15:04:39 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "[Cat contructor has been called]" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "[Cat destructor has been called]" << std::endl;
}

Cat::Cat(const Cat &rhs): Animal(rhs), _brain(new Brain(*rhs._brain))
{
	std::cout << "[Cat copy constructor has been called !]" << std::endl;
}

Cat&	Cat::operator=(const Cat &rhs)
{
	std::cout << "{Cat assignement operator has been called}" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAW !" << std::endl;
}

void	Cat::wants( void ) const
{
	std::cout << getType() << " wants " <<  _brain->getIdea(rand() % 100) << std::endl;
}