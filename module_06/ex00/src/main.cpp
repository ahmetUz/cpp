/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:02:55 by auzun             #+#    #+#             */
/*   Updated: 2023/02/19 21:00:04 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Litteral.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid argument : there is none or several arguments" << std::endl;
		return (1);
	}

	Litteral	converter(av[1]);
	converter.convert();
	converter.putall();
	return (0);
}