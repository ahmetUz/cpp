/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:08:10 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 13:19:43 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &p);
		~Point();

		Point&	operator=(const Point &rhs);
	
		Fixed	getX(void)const;
		Fixed	getY(void)const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif