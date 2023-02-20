/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:05:16 by auzun             #+#    #+#             */
/*   Updated: 2023/02/20 17:13:49 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialisation.hpp"

int	main( void )
{
	uintptr_t	voiciUnPtr = 0;

	Data	voiciUneData;
	Data*	voiciUneNouvelleData = NULL;

	voiciUneData.value = 43;

	printDataValue(&voiciUneData);
	printDataValue(voiciUneNouvelleData);
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	voiciUnPtr = serialize(&voiciUneData);
	printDataValue(&voiciUneData);
	printDataValue(voiciUneNouvelleData);
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	voiciUneNouvelleData = deserialize(voiciUnPtr);
	printDataValue(&voiciUneData);
	printDataValue(voiciUneNouvelleData);
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;
	return (0);
}