/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/02/22 03:40:59 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define	SIZE_ARRAY 4

// int main( void )
// {
// 	const AAnimal* j = new Dog();
// 	const AAnimal* i = new Cat();

// 	delete j;
// 	delete i;

// 	return (0);
// }

int main( void )
{
	AAnimal	*AAnimals[SIZE_ARRAY];

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (i % 2 == 0)
			AAnimals[i] = new Dog;
		else
			AAnimals[i] = new Cat;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		AAnimals[i]->wants();
		AAnimals[i]->wants();
		AAnimals[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete AAnimals[i];
		std::cout << std::endl;
	}

	return 0;
}