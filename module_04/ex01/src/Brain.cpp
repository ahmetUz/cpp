/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:45:53 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 13:56:31 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "[Brain contructor has been called]" << std::endl;
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
