/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileR.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:43:17 by auzun             #+#    #+#             */
/*   Updated: 2023/01/03 23:09:15 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILER_HPP
# define FILER_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>

#define EXIT_SUCESS 0
#define EXIT_FAILURE 1

class FileR
{
	private:
		std::string	_inF;
		std::string	_outF;
	public:
		FileR(std::string file_name);
		~FileR();
	void	replace(std::string s1, std::string s2);
};

#endif