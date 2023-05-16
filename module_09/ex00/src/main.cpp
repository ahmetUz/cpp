/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:53:00 by auzun             #+#    #+#             */
/*   Updated: 2023/05/16 13:56:57 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr <<  "Error: Invalid argument" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
	}
	catch(BitcoinExchange::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}