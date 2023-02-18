/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:24 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 17:00:42 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm():
	_name("default"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm( const AForm & src ):
	_name(src._name), _isSigned(false), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	if (this->_gradeToExec < 1 || this->_gradeToSign < 1)
		throw AForm::GradeTooHighExeption();
	else if (this->_gradeToExec > 150 || this->_gradeToSign > 150)
		throw AForm::GradeTooLowExeption();
}

AForm::AForm( std::string const name, const int gradeToSign, const int gradeToExec):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToExec < 1 || this->_gradeToSign < 1)
		throw AForm::GradeTooHighExeption();
	else if (this->_gradeToExec > 150 || this->_gradeToSign > 150)
		throw AForm::GradeTooLowExeption();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
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

void		AForm::beSigned( Bureaucrat const & br )
{
	if (br.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowExeption();
	else
		this->_isSigned = true;
}

void		AForm::beExecuted( Bureaucrat const & br ) const
{
	if (!getIsSigned())
		throw AForm::NonSignedExeption();
	else if (br.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowExeption();
}


const char *			AForm::GradeTooHighExeption::what() const throw()
{
	return ("Grade is too high!");
}

const char *			AForm::NonSignedExeption::what() const throw()
{
	return ("Form is unsigned!");
}

const char *			AForm::GradeTooLowExeption::what() const throw()
{
	return ("Grade is too low!");
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string			AForm::getName() const
{
	return (this->_name);
}

int					AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int					AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

bool						AForm::getIsSigned() const
{
	return (this->_isSigned);
}



/* ************************************************************************** */