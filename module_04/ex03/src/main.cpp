/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 05:39:44 by auzun             #+#    #+#             */
/*   Updated: 2023/01/30 21:31:07 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void )
{
	IMateriaSource*	src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	std::cout << std::endl;

	src->learnMateria(new Cure());
	std::cout << std::endl;

	src->learnMateria(new Cure());
	std::cout << std::endl;

	src->learnMateria(new Ice());
	std::cout << std::endl;

	src->learnMateria(new Ice());

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	ICharacter*	me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	me->equip(src->createMateria("fire"));
	std::cout << std::endl;

	me->equip(src->createMateria("lightning"));
	std::cout << std::endl;

	me->equip(src->createMateria("ice"));

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	ICharacter*	zoubir = new Character("zoubir");
	std::cout << std::endl;

	me->use(0, *zoubir);
	me->use(1, *zoubir);
	me->use(2, *zoubir);
	me->use(3, *zoubir);
	me->use(4, *zoubir);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	delete zoubir;
	std::cout << std::endl;

	delete me;
	std::cout << std::endl;

	delete src;
}