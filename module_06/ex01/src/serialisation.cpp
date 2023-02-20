/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialisation.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:55:22 by auzun             #+#    #+#             */
/*   Updated: 2023/02/20 17:08:27 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialisation.hpp"

uintptr_t serialize(Data* ptr)
{
	std::cout << "serialize --> convert data to uintptr_t" << std::endl;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	std::cout << "deserialize --> convert  uintptr_t to data" << std::endl;
	return (reinterpret_cast<Data *>(raw));
}

void	printDataValue(Data *src)
{
	if (src)
		std::cout << "ADR = " << src << " --> Value = " << src->value << std::endl;
	else
		std::cout << "src point to void !" << std::endl;
}
