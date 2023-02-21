/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:31:58 by auzun             #+#    #+#             */
/*   Updated: 2023/02/21 18:59:14 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T>
class Array
{
	private:
		T*				_array;
		int	_size;
	public:
		Array()
		{
			std::cout << "default constructor" << std::endl;
			_array = NULL;
			_size = 0;
		}
		Array(unsigned int n)
		{
			std::cout << "constructor" << std::endl;
			_array = new T[n];
			_size = n;
			for (int i = 0; i < _size; i++)
				_array[i] = 0;
		}
		Array(const Array& src)
		{
			std::cout << "copy constructor" << std::endl;
			_array = new T[src._size];
			*this = src;
		}
		~Array()
		{
			std::cout << "default desstructor" << std::endl;
			delete [] _array;
		}

		class ArrayException: public std::exception
		{
			public:
				virtual const char*	what(void) const throw() { return ("[Exception] Invalid Index, far from array scope");}
		};

		Array &	operator=(const Array &rhs)
		{
			_size = rhs._size;
			for (int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return (*this);
		}

		T&	operator[](int index)
		{
			if (index < 0 || index >= _size)
				throw (ArrayException());
			return(_array[index]);
		}
		
		int	size (void) const
		{
			return (_size);
		}
};


#endif