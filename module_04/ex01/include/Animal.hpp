/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:44:58 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 14:58:26 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*En C++, les destructeurs virtuels permettent de nettoyer les ressources allouées
pour une instance d'une classe qui en hérite avant qu'elle soit détruite. Le destructeur
virtuel est appelé automatiquement lorsque l'objet est supprimé, ce qui garantit que les
ressources sont libérées même si une référence à 
un objet de sous-classe est utilisée pour accéder à un objet de classe de base. Cela évite
les fuites de mémoire et autres problèmes liés à la gestion des ressources.*/

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &rhs);
		Animal&	operator=(const Animal &rhs);
	
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual void	wants(void) const;
};

#endif