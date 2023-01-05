/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 03:37:56 by auzun             #+#    #+#             */
/*   Updated: 2023/01/05 11:35:55 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPointNb;
		static const int	_fractionalPartBits = 8;
	public:
		Fixed();
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed(const Fixed &rhs);
		~Fixed();
		Fixed			&operator=(const Fixed &rhs);
		
		int				getRawBits(void) const;
		void			setRawBits(int const raw);

		float			toFloat(void) const;
		int				toInt(void) const;

		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed&			operator++(void);
		Fixed&			operator--(void);
		
		Fixed			operator+(const Fixed &rhs) const;
		Fixed			operator-(const Fixed &rhs) const;
		Fixed			operator*(const Fixed &rhs) const;
		Fixed			operator/(const Fixed &rhs) const;

		bool			operator>(const Fixed &rhs) const;
		bool			operator<(const Fixed &rhs) const;
		bool			operator>=(const Fixed &rhs) const;
		bool			operator<=(const Fixed &rhs) const;
		bool			operator!=(const Fixed &rhs) const;
		bool			operator==(const Fixed &rhs) const;
	
		static Fixed&	min(Fixed &a, Fixed &b);
		static const	Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const	Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif