/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:08:52 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 16:28:57 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default")
{
	std::cout << "[ShrubberyCreationForm] default constructor !" << std::endl;
	std::cout << *this << "appeared ! " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "[ShrubberyCreationForm] constructor !" << std::endl;
	std::cout << *this << "appeared ! " << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : AForm(src)
{
	*this = src;
	std::cout << "[ShrubberyCreationForm] copy constructor !" << std::endl;
	std::cout << *this << "appeared ! " << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] destructor." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	_isSigned = rhs._isSigned;
	_target = rhs._target;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	beExecuted(executor);
	std::ofstream	out((_target + "_shrubbery").c_str());

	out << "                                      &&& &&  & &&" << std::endl;
	out << "                                  && &\\/&\\|& ()|/ @, &&" << std::endl;
	out << "                                  &\\/(/&/&||/& /_/)_&/_&             ,@@@@@@@," << std::endl;
	out << "       _-_                     &() &\\/&|()|/&\\/ '%\" & ()        ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	out << "    /~~   ~~\\                 &_\\_&&_\\ |& |&&/&__%_/_& &&    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	out << " /~~         ~~\\      ###   &&   && & &| &| /& & % ()& /&&  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	out << "{               }    #o###   ()&_---()&\\&\\|&&-&&--%---()~   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	out << " \\  _-     -_  /   #####o###     &&     \\|||                %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	out << "   ~  \\\\ //  ~    #o#\\#|#/###            |||                `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	out << "_- -   | | _- _    ###\\|/#o#             |||                    |o|        | |         | |" << std::endl;
	out << "  _ -  | |   -_     # }|{  #             |||                    |.|        | |         | |" << std::endl;
	out << "\\  \\\\ // \\\\  \\\\ \\  \\\\ }|{   \\  \\ \\ , -=-~  .-^- _ \\  \\ \\ \\\\  \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

	out.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */