/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:37:10 by auzun             #+#    #+#             */
/*   Updated: 2023/02/21 19:52:32 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "[Bureaucrat] default constructor" << std::endl;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name), _grade(grade)
{
	std::cout << "[Bureaucrat] constructor" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade)
{
	std::cout << "[Bureaucrat] copy constructor" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat]  desstructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
		this->_grade = rhs._grade;
	return (*this);
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char *				Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too High!");
}

const char *				Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too Low!");
}

void						Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void						Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void				Bureaucrat::signForm( AForm &fr ) const
{
	try
	{
		fr.beSigned(*this);
		std::cout << *this << " signed " << fr;
	}
	catch(AForm::GradeTooLowExeption& e)
	{
		std::cout << *this << " couldn’t sign " << fr << " because  " << std::endl;
		std::cout << e.what() << '\n';
	}
}

void				Bureaucrat::executeForm( AForm const & form )
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch(AForm::FormException& e)
	{
		std::cout << getName() << " couldn’t executed " << form.getName() << "." << std::endl;
		std::cout << e.what() << '\n';
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string			Bureaucrat::getName() const
{
	return (this->_name);
}



/* ************************************************************************** */