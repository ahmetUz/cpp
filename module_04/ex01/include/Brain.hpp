/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:43:52 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 13:55:57 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		std::string	_ideas[100];
	public:

		Brain();
		Brain( Brain const & rhs );
		~Brain();

		Brain &				operator=( Brain const & rhs );
		std::string			getIdea(const int index) const;

};

#endif