/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:53:00 by auzun             #+#    #+#             */
/*   Updated: 2023/05/16 18:18:30 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	rpn;
	std::string	res;

	if (argc != 2)
	{
		std::cerr <<  "Error: Invalid argument" << std::endl;
		return (1);
	}
	res = rpn.compute(argv[1]);
	std::cout << res << std::endl;
	return (0);
}