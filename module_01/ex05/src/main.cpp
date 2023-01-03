/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:56:55 by auzun             #+#    #+#             */
/*   Updated: 2023/01/03 23:59:55 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
	std::string	input;
	Harl		harl;
	
	while (input.compare("exit"))
	{
		std::cout << "Enter a level: ";
		std::cin >> input;
		harl.complain(input);
	}
	
	return (0);
}