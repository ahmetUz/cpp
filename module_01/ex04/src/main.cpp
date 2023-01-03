/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:46:45 by auzun             #+#    #+#             */
/*   Updated: 2023/01/03 22:50:20 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileR.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Invalid arguments -> pleaze entre 1/{filename} 2/{to_fine} 3/{to_replace} " 
			<< std::endl;
		return (1);
	}
	FileR	f(av[1]);
	f.replace(av[2], av[3]);
	return (EXIT_SUCESS);
}