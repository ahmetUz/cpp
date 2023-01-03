/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileR.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:43:08 by auzun             #+#    #+#             */
/*   Updated: 2023/01/03 23:12:56 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileR.hpp"

FileR::FileR(std::string file_name) : _inF(file_name)
{
	this->_outF = file_name + ".replace";
}

FileR::~FileR()
{
}

/*La méthode c_str de std::string retourne un pointeur vers une chaîne 
de caractères terminée par un caractère nul (const char*) contenant
une copie des caractères de la chaîne de caractères std::string.*/

void	FileR::replace(std::string s1, std::string s2)
{
	std::ifstream	input(this->_inF.c_str());
	std::string		content;

	if (input.is_open())
	{
		if (std::getline(input, content, '\0'))
		{
			std::ofstream	ouput(this->_outF.c_str());
			size_t			i = content.find(s1);
			if (ouput.is_open())
			{
				if (i == std::string::npos)
					std::cerr << "Nothing to replace" << std::endl;
				while (i != std::string::npos)
				{
					content.erase(i, s1.length());
					content.insert(i, s2);
					i = content.find(s1);
				}
				ouput << content;
				ouput.close();
			}
			else
			{
				input.close();
				std::cerr << "Can not open --> " << this->_outF << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		else
			std::cerr << "Nothing to replace (Empty file / directory)" << std::endl;
		input.close();
	}
	else
	{
		std::cerr << "Can not open --> " << this->_inF << std::endl;
		exit(EXIT_FAILURE);
	}
}
