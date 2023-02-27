/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:52:48 by auzun             #+#    #+#             */
/*   Updated: 2023/02/27 21:59:05 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack<T>();
		MutantStack<T>( MutantStack const & src );
		~MutantStack<T>();

		MutantStack &		operator=( MutantStack const & rhs );

		typedef typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin() { return (this->c.begin());}
		iterator	end() { return (this->c.end());}
};

template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>(){}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src){}

template<typename T>
MutantStack<T>::~MutantStack(void){}

template<typename T>
MutantStack<T> &		MutantStack<T>::operator=( MutantStack const & rhs )
{
	std::stack<T>::operator=(rhs);
	return (*this);
}

template <typename T>
void	printElement(T i){
	std::cout << "[" << i << "] ";
}


#endif /* ***************************************************** MUTANTSTACK_H */