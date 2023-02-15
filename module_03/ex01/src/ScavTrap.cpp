/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:44:12 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:10:41 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage =20;
	
	std::cout << "scavetrap " << this->_name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "scavtrap " << this->_name << " has been destructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	std::cout << "ScavTrap an copy of " << rhs._name << " has been created!" << std::endl;
	*this = rhs;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "claptrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "scavetrap " << this->_name << " need energy to attack!" << std::endl;
		return ;
	}
	std::cout << "scavetrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "claptrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout <<"scavetrap " << this->_name << " passed in Gate keeper MODDEEE!" << std::endl;
}
