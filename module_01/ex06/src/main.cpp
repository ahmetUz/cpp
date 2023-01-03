/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:56:55 by auzun             #+#    #+#             */
/*   Updated: 2023/01/04 00:17:01 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Invalid argument " << std::endl;
		return (1);
	}
	std::string	input = av[1];
	Harl		harl;
	harl.complain(input);
	return (0);
}