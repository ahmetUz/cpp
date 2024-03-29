/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 06:18:21 by auzun             #+#    #+#             */
/*   Updated: 2023/02/22 03:34:42 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &rhs);
		Cat&	operator=(const Cat &rhs);

		void	makeSound(void) const;
};

#endif