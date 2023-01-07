/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:44:12 by auzun             #+#    #+#             */
/*   Updated: 2023/01/06 20:57:06 by auzun            ###   ########.fr       */
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

void	ScavTrap::attack(const std::string& target)
{
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
	std::cout <<"scavetrap " << this->_name << " passed in Gate keeper MODDEEE!" << std::endl;
}