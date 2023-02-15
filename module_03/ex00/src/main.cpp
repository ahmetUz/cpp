/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 13:54:06 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "../include/ClapTrap.hpp"

int	main( void )
{
	ClapTrap	goku("Goku");
	std::cout << std::endl;

	goku.attack("God Usopp");
	goku.attack("God Usopp");
	goku.attack("God Usopp");
	std::cout << "God Usopp is invincible..." << std::endl;
	std::cout << std::endl;

	goku.takeDamage(9);
	goku.beRepaired(1);
	goku.beRepaired(2);
	goku.beRepaired(5);
	goku.beRepaired(10);
	goku.beRepaired(20);
	goku.beRepaired(50);
	goku.beRepaired(100);
	goku.beRepaired(150);
	goku.beRepaired(150);
	goku.attack("God Usopp");
	std::cout << std::endl;
	
	goku.takeDamage(999);
	goku.beRepaired(1);
	goku.attack("God Usopp");
	std::cout << "God Usopp has destroyed Goku..." << std::endl;
	std::cout << std::endl;

	{
		ClapTrap	gokuCopy(goku);
	}

	std::cout << std::endl;
	return (0);
}