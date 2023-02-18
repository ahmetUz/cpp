/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:15:50 by auzun             #+#    #+#             */
/*   Updated: 2023/02/18 17:32:40 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		AForm*	makeShurbbery(std::string tr);
		AForm*	makeRobotomy(std::string tr);
		AForm*	makePresidential(std::string tr);

		AForm*	makeForm(std::string formName, std::string targetForm);

		Intern &		operator=( Intern const & rhs );

	private:
		int			_nbFormsType;
		std::string	_formsType[3];
		AForm*	(Intern::*_makeForm[3])(std::string);

};

#endif /* ********************************************************** INTERN_H */