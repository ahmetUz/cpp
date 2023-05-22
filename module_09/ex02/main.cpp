/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:53:00 by auzun             #+#    #+#             */
/*   Updated: 2023/05/22 11:17:34 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        try
        {
            PmergeMe merge(argv + 1);
        }
        catch (PmergeMe::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cerr << "Error: Bad arguments number" <<  std::endl;
    return (0);
}
