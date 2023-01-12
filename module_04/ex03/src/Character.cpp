/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 04:48:16 by auzun             #+#    #+#             */
/*   Updated: 2023/01/12 05:58:17 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(): _name("")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default Character s constructor has been called" << std::endl;
}

Character::Character( std::string const &name ): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Character s constructor has been called ! -> HI " << this->_name << std::endl;
}


Character::Character( const Character & src )
{
	*this = src;
	std::cout << "Character s copy constructor has been called ! -> HI " << this->_name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << this->_name << "has been destroyed !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				Character::equip(AMateria* m)
{
	int	i = 0;
	for (i = 0; i <= 4 && this->_inventory[i]; i++);
	if (i == 4)
	{
		std::cout << this->_name << "'s inventory is full !" << std::endl;
		return ;
	}
	this->_inventory[i] = m;
}

void				Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->_inventory[idx])
	{
		std::cout << this->_name << " unequiped " << this->_inventory[idx] << std::endl;
		delete _inventory[idx];
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << this->_name << " can't unequiped this, there is no materia there!" << std::endl;
}

void				Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		std::cout << this->_name << " use " << this->_inventory[idx]->getType() << std::endl;
	}
	else
		std::cout << this->_name << " cant use this!" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Character::getName() const
{
	return (this->_name);
}

/* ************************************************************************** */