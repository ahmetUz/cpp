/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:12:02 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 03:26:36 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int	main(void)
{
	Contact c;
	c.set_atr(1);
	std::cout << "first " << c.first_name \
	 << std::endl <<  "second " << c.last_name <<  \
	std::endl << "nick " << c.nickname;
	return (0);
}