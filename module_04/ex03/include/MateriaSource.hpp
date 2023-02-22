/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 05:27:52 by auzun             #+#    #+#             */
/*   Updated: 2023/02/22 03:37:46 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materia[4];
	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		virtual ~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
		
};

#endif