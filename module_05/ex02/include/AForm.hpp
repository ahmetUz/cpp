/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:18 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 16:59:55 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

	public:

		AForm( AForm const & src );
		AForm( std::string const name, const int gradeToSign, const int gradeToExec);
		~AForm();

		const std::string			getName() const;
		int							getGradeToSign() const;
		int							getGradeToExec() const;
		bool						getIsSigned() const;

		void		beSigned( Bureaucrat const & br );
		void		beExecuted( Bureaucrat const & br ) const;

		AForm &		operator=( AForm const & rhs );

		class FormException : public std::exception
		{
			public :
				virtual const char * what( void ) const throw() = 0;
		};

		class GradeTooHighExeption : public FormException
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowExeption : public FormException
		{
			public:
				virtual const char * what() const throw();
		};
		class NonSignedExeption : public FormException
		{
			public:
				virtual const char * what() const throw();
		};

		virtual void execute(Bureaucrat const & executor) const = 0;

	protected:
		AForm();
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */