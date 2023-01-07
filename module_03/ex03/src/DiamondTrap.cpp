/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:27:38 by auzun             #+#    #+#             */
/*   Updated: 2023/01/07 10:05:11 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDamage = 30;
	std::cout << "diamondtrap " << this->_name << " has been created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "diamondtrap " << this->_name << " has been destructed!" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " / ClapTrap name " << ClapTrap::_name << std::endl;
}