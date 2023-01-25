/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:37:10 by auzun             #+#    #+#             */
/*   Updated: 2023/01/25 19:19:36 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::gradeTooHighExeption();
	else if (grade > 150)
		throw Bureaucrat::gradeTooLowExeption();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::gradeTooHighExeption();
	else if (this->_grade > 150)
		throw Bureaucrat::gradeTooLowExeption();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
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

const char *				Bureaucrat::gradeTooHighExeption::what() const throw()
{
	return ("Grade is too High!");
}

const char *				Bureaucrat::gradeTooLowExeption::what() const throw()
{
	return ("Grade is too Low!");
}

void						Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::gradeTooHighExeption();
}

void						Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::gradeTooLowExeption();
}

void				Bureaucrat::signForm( Form fr ) const
{
	if (fr.getIsSigned())
		std::cout << *this << " signed " << fr;
	else if (fr.getGradeToSign() < this->_grade)
		std::cout << *this << " couldn’t sign " << fr << " because his grade is too low " << std::endl;
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