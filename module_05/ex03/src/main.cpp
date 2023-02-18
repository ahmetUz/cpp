/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:31AForm:40 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 17:47:53 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int	main( void )
{
	Bureaucrat	nouveau("Célestin", 150);
	Bureaucrat	manager("Titouanville", 75);
	Bureaucrat	boss("M.Landolsi", 1);

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;

	Intern		slave;
	std::cout << std::endl;

	AForm*	trees = slave.makeForm("shrubbery creation", "Tree");
	std::cout << std::endl;

	AForm*	robot = slave.makeForm("robotomy request", "Dimitri");
	std::cout << std::endl;

	AForm*	zaphod = slave.makeForm("presidential pardon", "Titouan");
	std::cout << std::endl;

	AForm*	fail = slave.makeForm("ytb tutorial get summer body in 3 days without sport", "lol");
	(void)fail;

	std::cout << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << std::endl;
	
	nouveau.executeForm(*zaphod);
	boss.signForm(*zaphod);
	nouveau.executeForm(*zaphod);
	std::cout << std::endl;

	boss.signForm(*trees);
	manager.executeForm(*trees);
	std::cout << std::endl;

	boss.signForm(*robot);
	boss.executeForm(*robot);
	boss.executeForm(*robot);
	std::cout << std::endl;

	boss.signForm(*zaphod);
	boss.executeForm(*zaphod);
	std::cout << std::endl;

	delete trees;
	delete robot;
	delete zaphod;

	return (0);
}