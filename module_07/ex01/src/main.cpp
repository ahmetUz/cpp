/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:24:09 by auzun             #+#    #+#             */
/*   Updated: 2023/02/21 18:27:47 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define SIZE_MAX 3

int main( void )
{
	int			arrayInt[] = {1, 2, 3};
	char		arrayChar[] = {'a', 'b', 'c'};
	std::string	arrayString[] = {"Hello", "Hola", "Sawubona (bonjour en Zoulou)"};

	iter(arrayInt, SIZE_MAX, show<int>);
	std::cout << std::endl;

	iter(arrayChar, SIZE_MAX, show<char>);

	// iter(arrayString, SIZE_MAX, badDisplay); (ne compile pas)

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	iter(arrayInt, SIZE_MAX, show<int>);
	std::cout << std::endl;

	iter(arrayChar, SIZE_MAX, show<char>);
	std::cout << std::endl;

	iter(arrayString, SIZE_MAX, show<std::string>);

	return (0);
}