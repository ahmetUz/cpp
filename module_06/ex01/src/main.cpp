/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:05:16 by auzun             #+#    #+#             */
/*   Updated: 2023/02/23 22:14:04 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	printDataValue(Data *src)
{
	if (src)
		std::cout << "ADR = " << src << " --> Value = " << src->value << std::endl;
	else
		std::cout << "src point to void !" << std::endl;
}



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

	voiciUnPtr = Serializer::serialize(&voiciUneData);
	printDataValue(&voiciUneData);
	printDataValue(voiciUneNouvelleData);
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	voiciUneNouvelleData = Serializer::deserialize(voiciUnPtr);
	printDataValue(&voiciUneData);
	printDataValue(voiciUneNouvelleData);
	std::cout << "Uintptr = " << voiciUnPtr << std::endl;
	return (0);
}