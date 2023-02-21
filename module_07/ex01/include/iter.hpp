/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:16:48 by auzun             #+#    #+#             */
/*   Updated: 2023/02/21 18:26:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	show(T toShow)
{
	std::cout << toShow << ", ";
}

template< typename U, typename V, typename W >
void	iter( U *array, V size, W function)
{
	for (int i = 0; i < size; i++)
	{
		function(array[i]);
	}
}

#endif