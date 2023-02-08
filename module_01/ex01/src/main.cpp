/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:08:55 by auzun             #+#    #+#             */
/*   Updated: 2023/02/08 15:04:46 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 10

int main(void)
{
	Zombie *zombies = zombieHorde(0, "pas bien");
	std::cout << std::endl;

	zombies = zombieHorde(3, "VROUM VROUM LA TUTURE");
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Z" << i << " "; 
		zombies[i].announce();
	}
	std::cout << std::endl;

	delete [] zombies;
	return (0);
}