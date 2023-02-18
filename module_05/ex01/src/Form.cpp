/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:24 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 16:22:17 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form( const Form & src ):
	_name(src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	if (this->_gradeToExec < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighExeption();
	else if (this->_gradeToExec > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowExeption();
}

Form::Form( std::string const name, const int gradeToSign, const int gradeToExec):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToExec < 1 || this->_gradeToSign < 1)
		throw Form::GradeTooHighExeption();
	else if (this->_gradeToExec > 150 || this->_gradeToSign > 150)
		throw Form::GradeTooLowExeption();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form: " << std::endl << "name : " << i.getName() << std::endl
		<< "grade to sign: " << i.getGradeToSign() << std::endl
		<< "grade to execute: " << i.getGradeToExec() << std::endl
		<< "is signed: " << (i.getIsSigned() ? "Signed" : "Unsigned") << std::endl;
	return (o);
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::beSigned( Bureaucrat const & br )
{
	if (br.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowExeption();
	else
		this->_isSigned = true;
}

const char *			Form::GradeTooHighExeption::what() const throw()
{
	return ("Grade is too high!");
}

const char *			Form::GradeTooLowExeption::what() const throw()
{
	return ("Grade is too low!");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string			Form::getName() const
{
	return (this->_name);
}

int					Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool						Form::getIsSigned() const
{
	return (this->_isSigned);
}



/* ************************************************************************** */