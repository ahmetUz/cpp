/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:07:35 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:07:47 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ScavTrap.hpp"

int	main( void )
{
	ClapTrap	yamcha("Yamcha");
	std::cout << std::endl;

	ScavTrap	goku("Goku");
	std::cout << std::endl;

	goku.attack("God Usopp");
	goku.attack("God Usopp");
	goku.attack("God Usopp");
	std::cout << "This damages is insignificant for God Usopp..." << std::endl;
	std::cout << std::endl;

	goku.takeDamage(99);
	goku.beRepaired(10);
	goku.beRepaired(20);
	goku.beRepaired(50);
	goku.beRepaired(100);
	goku.beRepaired(200);
	goku.beRepaired(500);
	goku.beRepaired(1000);
	goku.beRepaired(1500);
	goku.beRepaired(1500);
	goku.attack("God Usopp");
	std::cout << std::endl;
	
	goku.guardGate();
	std::cout << std::endl;

	goku.takeDamage(9999);
	goku.beRepaired(1);
	goku.attack("God Usopp");
	std::cout << "God Usopp has destroyed Goku again..." << std::endl;
	std::cout << std::endl;

	{
		ClapTrap	yamchaCopy(yamcha);
	}
		std::cout << std::endl;
	{
		ScavTrap	gokuCopy(goku);
	}

	std::cout << std::endl;
	return (0);
}
