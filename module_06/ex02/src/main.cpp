/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:44:39 by auzun             #+#    #+#             */
/*   Updated: 2023/02/20 17:49:04 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.hpp"

int	main( void )
{
	srand(time(NULL));
	Base*	base1 = generate();
	Base*	base2 = generate();
	Base*	base3 = generate();

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	identify(base1);
	identify(base2);
	identify(base3);
	std::cout << std::endl;

	identify(NULL);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	identify(*base1);
	identify(*base2);
	identify(*base3);	

	delete base1;
	delete base2;
	delete base3;
	return (0);
}