/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:45:05 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 12:01:12 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNb = 0;
}

Fixed::Fixed(int const nb)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNb = nb << Fixed::_fractionalPartBits;
}

Fixed::Fixed(float const nb)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNb = roundf(nb * (1 << Fixed::_fractionalPartBits));
}

Fixed::Fixed(const Fixed &rhs)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNb = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointNb);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointNb = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointNb / (float)(1 << Fixed::_fractionalPartBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointNb >> Fixed::_fractionalPartBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	tmp._fixedPointNb = this->_fixedPointNb++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	tmp._fixedPointNb = this->_fixedPointNb--;
	return (tmp);
}

Fixed&	Fixed::operator++(void)
{
	this->_fixedPointNb++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_fixedPointNb--;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

Fixed&			Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed&			Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}