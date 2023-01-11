/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:13:54 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 06:47:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "[Dog contructor has been called]" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "[Dog destructor has been called]" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WOAF !" << std::endl;
}
