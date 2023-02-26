/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:45:04 by auzun             #+#    #+#             */
/*   Updated: 2023/02/26 21:18:45 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }


#define GREEN(s) "\033[1;32m" s "\033[m"
#define BLUE(s) "\033[1;34m" s "\033[m"
#define RED(s) "\033[1;31m" s "\033[m"

// int main(void) 
// {
// 	Span	sp = Span(5);     // list of 5 elements max

// 	std::cout << "List at initialization: " << sp << std::endl;
// 	try
// 	{
// 		std::cout << BLUE("Test: ") << "Trying to get shortest span of an empty list:" << std::endl;
// 		std::cout << sp.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << RED("Error: ") << e.what() << std::endl;
// 	}

// 	std::cout << BLUE("Test: ") << "Now adding one number" << std::endl;
// 	sp.addNumber(5);
// 	std::cout << sp << std::endl;
// 	try
// 	{
// 		std::cout << BLUE("Test: ") << "Trying to get shortest span in list:" << std::endl;
// 		std::cout << sp.shortestSpan() << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << RED("Error: ") << e.what() << std::endl;
// 	}
	
// 	std::cout << BLUE("Test: ") << "Now adding more numbers one by one:" << std::endl;
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(7);
// 	sp.addNumber(11);
// 	std::cout << sp << std::endl;
// 	try
// 	{
// 		std::cout << BLUE("Test: ") << "Trying to add one more number:" << std::endl;
// 		sp.addNumber(42);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << RED("Error: ") << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		std::cout << BLUE("Test: ") << "Trying to get shortest span in list" << std::endl;
// 		std::cout << "Shortest span: [" << sp.shortestSpan() << "]" << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << RED("Error: ") << e.what() << std::endl;
// 	}
	
	
// 	std::cout << BLUE("Lets create a new list and add multiple numbers at once:") << std::endl;
// 	Span newList(10);
// 	newList.addNumber(42);
// 	std::vector<int>::const_iterator begin = sp.getList().begin();
// 	std::vector<int>::const_iterator end = sp.getList().end();

// 	newList.addMultipleNumber(begin, end);
// 	newList.addMultipleNumber(begin, end - 1);

// 	std::cout << "New list:\n" << newList << std::endl;

// 	std::cout << "Shortest span: [" << newList.shortestSpan() << "]" << std::endl;
// 	std::cout << "Longest span:  [" << newList.longestSpan() << "]" << std::endl;
// 	std::cout << std::endl;


// 	return 0;
// }


#define SIZE_MAX 50

// int	main( void )
// {
// 	Span sp(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	sp.printSpan();

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return (0);
// }

void	printElement(int i){
	std::cout << "[" << i << "] ";
}

int	getRandomNumber( void ){
	return (std::rand() % SIZE_MAX);
}

void	fill(Span &src, int value)
{
	for (unsigned int i = 0; i < src.getSize(); i++)
	{
		src.addNumber(value);

	}
}

void	randomFill(Span &src)
{
	for (unsigned int i = 0; i < src.getSize(); i++)
	{
		src.addNumber(getRandomNumber());
	}
}

int	main( void )
{
	std::srand(time(NULL));

	Span spoun(5);
	std::for_each(spoun.getList().begin(), spoun.getList().end(), printElement);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	randomFill(spoun);
	std::for_each(spoun.getList().begin(), spoun.getList().end(), printElement);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	try
	{
		spoun.addNumber(0);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	try
	{
		std::cout << spoun << std::endl;
		std::cout << "Shortest span is " << spoun.shortestSpan() << std::endl;
		std::cout << "Longest span is " << spoun.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	std::cout << "😪 😪 😪 😪 😪 😪 😪" << std::endl;
	Span ultimateSpoun(10000);

	randomFill(ultimateSpoun);
	std::cout << ultimateSpoun << std::endl;
	std::cout << "U Shortest span is " << ultimateSpoun.shortestSpan() << std::endl;
	std::cout << "U Longest span is " << ultimateSpoun.longestSpan() << std::endl;

	return (0);
}