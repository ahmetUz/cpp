/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:50:58 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define	SIZE_ARRAY 4

// int main( void )
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j;
// 	delete i;

// 	return (0);
// }

int main( void )
{
	Animal	*animals[SIZE_ARRAY];

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		animals[i]->wants();
		animals[i]->wants();
		animals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	return 0;
}
