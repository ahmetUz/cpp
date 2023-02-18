/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:23:02 by auzun             #+#    #+#             */
/*   Updated: 2023/02/17 16:35:40 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{

	public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		void execute(Bureaucrat const & executor) const;

	private:
		PresidentialPardonForm();
		std::string	_target;

};

#endif /* ************************************** PresidentialPardonForm_H */