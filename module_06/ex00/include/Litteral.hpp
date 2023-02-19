/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Litteral.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:05:23 by auzun             #+#    #+#             */
/*   Updated: 2023/02/19 21:28:08 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTERAL_HPP
# define LITTERAL_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <limits>
# include <cstdlib>

enum	e_type
{
	NONE,
	INT,
	FLOAT,
	CHAR,
	DOUBLE
};

class Litteral
{

	public:

		Litteral(const char *);
		Litteral( Litteral const & src );
		~Litteral();

		Litteral &		operator=( Litteral const & rhs );

		bool	isChar( void ) const;
		bool	isInt( void ) const;
		bool	isFloat( void ) const;
		bool	isDouble( void ) const;
		bool	isLiteral( void ) const;
		
		void	setType(void);

		void	putChar( void ) const;
		void	putInt( void ) const;
		void	putFloat( void ) const;
		void	putDouble( void ) const;
		void	putall( void ) const;

		void	convert(void);

	private:
		Litteral();

		std::string	_str;
		bool		_impossible;
		e_type		_type;

		char	_c;
		int		_i;
		float	_f;
		double	_d;


};

#endif /* ******************************************************** LITTERAL_H */