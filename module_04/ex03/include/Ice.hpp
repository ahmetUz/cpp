/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:38:28 by auzun             #+#    #+#             */
/*   Updated: 2023/02/22 03:37:37 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice( Ice const & src );
		virtual ~Ice();

		Ice &		operator=( Ice const & rhs );

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter& target);

};

#endif