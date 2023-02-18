/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:57:05 by auzun             #+#    #+#             */
/*   Updated: 2023/02/17 15:57:21 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:
		ShrubberyCreationForm( const std::string& target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		void execute(Bureaucrat const & executor) const;

	private:
		ShrubberyCreationForm();
		std::string	_target;

};

#endif /* *************************************** ShrubberyCreationForm_H */