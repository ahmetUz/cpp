/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:19:41 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 06:47:16 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "[Cat contructor has been called]" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "[Cat destructor has been called]" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "MIAW !" << std::endl;
}