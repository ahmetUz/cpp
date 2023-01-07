/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:58:55 by auzun             #+#    #+#             */
/*   Updated: 2023/01/06 20:31:26 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "claptrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "claptrap " << this->_name << " has been destructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	std::cout << "claptrap an copy of " << rhs._name << " has been created!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "claptrap " << this->_name << " need energy to attack!" << std::endl;
		return ;
	}
	std::cout << "claptrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= amount)
	{
		std::cout << "claptrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << "claptrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "claptrap " << this->_name << " need energy to repair!" << std::endl;
		return ;
	}
		std::cout << "claptrap " << this->_name << " repair itself for " << amount << " hit points" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}
