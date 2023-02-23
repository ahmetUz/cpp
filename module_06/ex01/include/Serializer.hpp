/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:03:32 by auzun             #+#    #+#             */
/*   Updated: 2023/02/23 22:12:06 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	int	value;
};

class Serializer
{

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		static void	printDataValue(Data *src);

	private:
		Serializer();
		Serializer &		operator=( Serializer const & rhs );
		Serializer( Serializer const & src );
		~Serializer();

};

#endif /* ****************************************************** SERIALIZER_H */