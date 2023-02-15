/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:45:53 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 15:09:44 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "[Brain] Default constructor called." << std::endl;
	srand(time(NULL));
	int	i = 0;

	while (i < 2)
		_ideas[i++] = "to destroy the world";
	while (i < 10)
		_ideas[i++] = "to burn the world";
	while (i < 25)
		_ideas[i++] = "to poop in the living room";
	while (i < 40)
		_ideas[i++] = "to be caressed";
	while (i < 60)
		_ideas[i++] = "to sleep";
	while (i < 100)
		_ideas[i++] = "to eat";
}

Brain::Brain( const Brain & rhs )
{
	std::cout << "[Brain copy constructor has been called !]" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
}

Brain::~Brain()
{
	std::cout << "[Brain destructor has been called]" << std::endl;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

std::string	Brain::getIdea(const int index) const
{
	return (this->_ideas[index]);
}
