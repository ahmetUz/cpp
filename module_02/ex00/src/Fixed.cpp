/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:45:05 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 04:11:16 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNb = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNb = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointNb = raw;
}