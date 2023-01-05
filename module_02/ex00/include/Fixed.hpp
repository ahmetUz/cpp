/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:37:56 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 04:08:26 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPointNb;
		static const int	_fractionalPartBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &rhs);
		Fixed	&operator=(const Fixed &rhs);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif