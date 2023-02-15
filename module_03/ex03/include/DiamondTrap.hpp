/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:21:29 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 12:29:40 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &rhs);
		~DiamondTrap();

		DiamondTrap	&operator=(const DiamondTrap &rhs);
	
	using	ScavTrap::attack;
	void	whoAmI();
};

#endif