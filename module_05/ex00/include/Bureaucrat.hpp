/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:39:59 by auzun             #+#    #+#             */
/*   Updated: 2023/01/24 19:29:02 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat( Bureaucrat const & src );
		Bureaucrat( std::string const name, int grade );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrad();
		void				decrementGrad();

		class gradeTooHighExeption : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class gradeTooLowExeption : public std::exception
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