/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:31:07 by auzun             #+#    #+#             */
/*   Updated: 2023/01/03 21:13:09 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& Weapon) : _name(name),_weapon(Weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void) const
{
	if (this->_weapon.getType() != "")
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " doesn't have a weapon to attack." << std::endl;
}