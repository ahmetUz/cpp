/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:13:54 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 15:15:23 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "[Dog contructor has been called]" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "[Dog destructor has been called]" << std::endl;
}

Dog::Dog(const Dog &rhs): AAnimal(rhs), _brain(new Brain(*rhs._brain))
{
	std::cout << "[Dog copy constructor has been called !]" << std::endl;
}

Dog&	Dog::operator=(const Dog &rhs)
{
	std::cout << "{Dog assignement operator has been called}" << std::endl;
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}


void	Dog::makeSound(void) const
{
	std::cout << "WOAF !" << std::endl;
}

void	Dog::wants( void ) const
{
	std::cout << getType() << " wants " <<  _brain->getIdea(rand() % 100) << std::endl;
}