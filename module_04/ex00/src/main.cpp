/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:36:03 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << meta->getType() << " : ";
	meta->makeSound();
	std::cout << std::endl;
	std::cout << dog->getType() << " : ";
	dog->makeSound();
	std::cout << cat->getType() << " : ";
	cat->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << wrongAnimal->getType() << " : ";
	wrongAnimal->makeSound();
	std::cout << wrongCat->getType() << " : ";
	wrongCat->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;


	delete meta;
	std::cout << std::endl;

	delete cat;
	delete dog;
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;

	return (0);
}