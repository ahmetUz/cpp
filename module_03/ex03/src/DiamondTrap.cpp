/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:27:38 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 13:51:22 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "diamondtrap " << this->_name << " has been created!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "diamondtrap copy " << this->_name << " has been created!" << std::endl;
	*this = rhs;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "diamondtrap " << this->_name << " has been destructed!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " / ClapTrap name " << ClapTrap::_name << std::endl;
}