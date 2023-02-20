/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialisation.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:49:52 by auzun             #+#    #+#             */
/*   Updated: 2023/02/20 17:02:46 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALISATION_HPP
# define SERIALISATION_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int	value;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
void	printDataValue(Data *src);

#endif