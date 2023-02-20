/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:27:30 by auzun             #+#    #+#             */
/*   Updated: 2023/02/20 17:46:30 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.hpp"

Base *	generate(void)
{
	int	random = (rand()%3);

	std::cout << "Generating ..." << std::endl;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void	identify(Base* p)
{
	try
	{
		if (!p)
			throw (std::exception());
		try
		{
			if (!dynamic_cast<A*>(p))
				throw (std::exception());
			std::cout << "TOUDOUM ITS AN [A]" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				if (!dynamic_cast<B*>(p))
					throw (std::exception());
				std::cout << "TOUDOUM ITS AN [B]" << std::endl;
			}
			catch(const std::exception& e)
			{
				try
				{
					if (!dynamic_cast<C*>(p))
						throw (std::exception());
					std::cout << "TOUDOUM ITS AN [C]" << std::endl;
				}
				catch(const std::exception& e)
				{
					std::cout << "p dont point to A, B or C !" << std::endl;
				}
				
			}
			
		}
		
	}
	catch (std::exception&)
	{
		std::cout << "p point to void !" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		if (!dynamic_cast<A*>(&p))
			throw (std::exception());
		std::cout << "TOUDOUM ITS AN [A]" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			if (!dynamic_cast<B*>(&p))
				throw (std::exception());
			std::cout << "TOUDOUM ITS AN [B]" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				if (!dynamic_cast<C*>(&p))
					throw (std::exception());
				std::cout << "TOUDOUM ITS AN [C]" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "p dont point to A, B or C !" << std::endl;
			}
			
		}
		
	}
}

