/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:36:57 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 12:25:05 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &rhs);
		~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &rhs);
		
		void attack(const std::string& target);
		void guardGate();
};

#endif