/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:35:33 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 17:53:28 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "[Intern] Default constructor!" << std::endl;
	this->_nbFormsType = 3;
	this->_formsType[0] = "shrubbery creation";
	this->_formsType[1] = "robotomy request";
	this->_formsType[2] = "presidential pardon";
	this->_makeForm[0] = &Intern::makeShurbbery;
	this->_makeForm[1] = &Intern::makeRobotomy;
	this->_makeForm[2] = &Intern::makePresidential;
}

Intern::Intern( const Intern & src )
{
	std::cout << "[Intern] copy constructor!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "[Intern] destructor !" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	this->_nbFormsType = rhs._nbFormsType;
	for (int i = 0; i < this->_nbFormsType; i++)
	{
		this->_formsType[i] = rhs._formsType[i];
		this->_makeForm[i]  = rhs._makeForm[i];
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
AForm*	Intern::makeShurbbery(std::string tr)
{
	return (new ShrubberyCreationForm(tr));
}

AForm*	Intern::makeRobotomy(std::string tr)
{
	return (new RobotomyRequestForm(tr));
}

AForm*	Intern::makePresidential(std::string tr)
{
	return (new PresidentialPardonForm(tr));
}

AForm*	Intern::makeForm(std::string formName, std::string targetForm)
{
	for(int i = 0; i < this->_nbFormsType; i++)
	{
		if (formName == this->_formsType[i])
		{
			std::cout << "Inter creates " << formName << std::endl;
			return ((this->*_makeForm[i])(targetForm));
		}
	}
	std::cout << "there is no " << formName << "type here !" << std::endl;
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */