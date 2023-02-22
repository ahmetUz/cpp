/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:09:01 by auzun             #+#    #+#             */
/*   Updated: 2023/02/22 03:37:35 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure( Cure const & src );
		virtual ~Cure();

		Cure &		operator=( Cure const & rhs );
		
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter& target);
};

#endif