/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:07:27 by auzun             #+#    #+#             */
/*   Updated: 2023/02/08 15:11:33 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
	{
		std::cout << name << " is invalid" << std::endl;
		return (NULL);
	}
	try
	{
		Zombie	*z = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			z[i].set_name(name);
		}
		return (z);
	}
	catch(std::bad_alloc&)
	{
		std::cout << "Allocation failed" << std::endl;
		return (NULL);
	}
}