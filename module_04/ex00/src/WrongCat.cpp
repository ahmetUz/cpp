/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:39:30 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 06:43:33 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat contructor has been called]" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat destructor has been called]" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MIAW !" << std::endl;
}