/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:04:00 by auzun             #+#    #+#             */
/*   Updated: 2023/02/21 18:10:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void	swap( T& a, T& b)
{
	T	c = a;
	a = b;
	b = c;
}

template< typename T >
T	min(T const& a, T const& b)
{
	return (a < b ? a : b);
}

template< typename T >
T	max(T const& a, T const& b)
{
	return (a > b ? a : b);
}

#endif