/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:23:05 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 13:34:46 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	return (((a.getX() * (b.getY() - c.getY()))
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY()))) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abc = abs(area(a, b, c));
	Fixed	pbc = abs(area(point, b, c));
	Fixed	pab = abs(area(point, a, b));
	Fixed	pac = abs(area(point, a, c));
	Fixed	result = pbc + pab + pac;
	if (abc == result)
		return (true);
	return (false);
}
