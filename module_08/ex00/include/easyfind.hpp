/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:20:21 by auzun             #+#    #+#             */
/*   Updated: 2023/02/21 19:25:00 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

template < typename T >
typename T::iterator	easyfind(T & container, int value)
{
	return (std::find(container.begin(), container.end(), value));
}

#endif