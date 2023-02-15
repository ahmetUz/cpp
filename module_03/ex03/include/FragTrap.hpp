/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 09:02:18 by auzun             #+#    #+#             */
/*   Updated: 2023/02/15 12:28:47 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &rhs);
		~FragTrap();

		FragTrap	&operator=(const FragTrap &rhs);
		
		void highFivesGuys(void);
};

#endif