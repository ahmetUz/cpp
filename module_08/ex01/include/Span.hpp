/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:45:50 by auzun             #+#    #+#             */
/*   Updated: 2023/02/26 21:09:29 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include<iostream>
#include<vector>
#include<algorithm>

class Span
{

	public:

		Span( unsigned int );
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );
	
		class FullSpan : public std::exception
		{
			public:
				const char *	what( void ) const throw() {return ("[Warning] the Span is full");}
		};
		class EmptySpan : public std::exception
		{
			public:
				const char *	what( void ) const throw() {return ("[Warning] the Span is empty");}
		};
		
		void	addMultipleNumber( std::vector<int>::const_iterator, std::vector<int>::const_iterator );
		void	addNumber( int nb );
		int		shortestSpan( void );
		int		longestSpan( void );

		std::vector<int> const &	getList() const;
		unsigned int				getSize() const;
	private:
		Span();
		unsigned int	_sizeMax;
		std::vector<int>	_list;
		

};

std::ostream &	operator<<(std::ostream &, Span const &);

#endif /* ************************************************************ SPAN_H */