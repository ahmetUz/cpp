/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:09:33 by auzun             #+#    #+#             */
/*   Updated: 2023/02/26 21:10:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(): _sizeMax(0)
{
}

Span::Span( unsigned int nb): _sizeMax(nb), _list(0)
{
}

Span::Span( const Span & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	_sizeMax = rhs._sizeMax;
	_list = rhs._list;
	return (*this);
}

std::ostream &	operator<<(std::ostream &o, Span const &ref)
{
	std::vector<int>::const_iterator it = ref.getList().begin();

	o << "[ ";
	for (; it != ref.getList().end() ; ++it)
	{
		o << *it;
		o << " ";
	}
	o << "]";
	
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber( int nb )
{
	if (_list.size() >= _sizeMax)
		throw (FullSpan());
	_list.push_back(nb);
}

void	Span::addMultipleNumber( std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	_list.insert(_list.begin(), begin, end);
	if (_list.size() >= _sizeMax)
		_list.resize(_sizeMax);
}

int		Span::shortestSpan( void )
{
	if (_list.empty())
		throw (EmptySpan());
	else if (_list.size() == 1 || _sizeMax == 1)
		return (*_list.begin());
	
	Span	tmp(*this);
	std::sort(tmp._list.begin(), tmp._list.end());

	int		rvalue = tmp._list.back() - tmp._list.front();
	int		last = tmp._list.front();
	for (std::vector<int>::const_iterator it = (tmp._list.begin()) + 1;
		it != tmp._list.end(); ++it)
	{
		if (*it - last < rvalue)
			rvalue = *it - last;
		last = *it;
	}
	return (rvalue);
}

int		Span::longestSpan( void )
{
	if (_list.empty())
		throw (EmptySpan());
	else if (_list.size() == 1 || _sizeMax == 1)
		return (*_list.begin());

	Span	tmp(*this);
	std::sort(tmp._list.begin(), tmp._list.end());
	return(tmp._list.back() - tmp._list.front());
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<int> const & Span::getList() const
{
	return (_list);
}

unsigned int			Span::getSize() const
{
	return (_sizeMax);
}


/* ************************************************************************** */
