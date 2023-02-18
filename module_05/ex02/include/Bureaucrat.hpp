/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:39:59 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 17:00:14 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
class AForm;

class Bureaucrat
{

	public:

		Bureaucrat( Bureaucrat const & src );
		Bureaucrat( std::string const name, int grade );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm( AForm& fr ) const;
		void				executeForm( AForm const & form );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
	private:
		Bureaucrat();

		const std::string				_name;
		int								_grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );
#endif