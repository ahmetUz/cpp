/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:01:18 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 17:10:24 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form;
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form( Form const & src );
		Form( std::string const name, const int gradeToSign, const int gradeToExec);
		~Form();

		const std::string			getName() const;
		int							getGradeToSign() const;
		int							getGradeToExec() const;
		bool						getIsSigned() const;

		void		beSigned( Bureaucrat const & br );

		Form &		operator=( Form const & rhs );

		class FormException : public std::exception
		{
			public :
				virtual const char* what( void ) const throw() = 0;
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

	private:
		Form();
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */