/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:37:04 by auzun             #+#    #+#             */
/*   Updated: 2023/01/11 17:52:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string	_type;

	public:

		AMateria();
		AMateria(std::string const & type);
		AMateria( AMateria const & src );
		virtual ~AMateria();
		
		AMateria &		operator=( AMateria const & rhs );

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif