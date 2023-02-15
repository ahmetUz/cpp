/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:02:20 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:18:59 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "fragtrap " << this->_name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs)
{
	std::cout << "FragTrap an copy of " << rhs._name << " has been created!" << std::endl;
	*this = rhs;
}

FragTrap::~FragTrap()
{
	std::cout << "fragtrap " << this->_name << " has been destructed!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &rhs)
{
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "claptrap " << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout <<"fragtrap " << this->_name << " high fives !" << std::endl;
}