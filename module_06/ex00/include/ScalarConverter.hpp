/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:57:09 by auzun             #+#    #+#             */
/*   Updated: 2023/02/23 22:00:41 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "Litteral.hpp"

class ScalarConverter
{

	public:
		static void		convert(std::string const str);

	private:
		~ScalarConverter();
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter &		operator=( ScalarConverter const & rhs );

};

#endif /* ************************************************* SCALARCONVERTER_H */