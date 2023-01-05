/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:07:36 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 13:22:48 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x) , _y(y)
{
}

Point::Point(const Point &p) : _x(p._x), _y(p._y)
{
}

Point::~Point()
{
}

Point&	Point::operator=(const Point &rhs)
{
	(Fixed) this->_x = rhs._x;
	(Fixed) this->_y = rhs._y;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}