/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:02:20 by auzun             #+#    #+#             */
/*   Updated: 2023/01/07 09:14:51 by auzun            ###   ########.fr       */
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

FragTrap::~FragTrap()
{
	std::cout << "fragtrap " << this->_name << " has been destructed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout <<"fragtrap " << this->_name << " high fives !" << std::endl;
}