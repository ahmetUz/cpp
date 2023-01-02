/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:13:53 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 22:09:54 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		int		nb_contacts;
		Contact contacts[8];
		int		get_nb_contact() const;
		int		get_index() const;
	public:
		PhoneBook();
		~PhoneBook();
		void	set_nb_contact(int nb);
		void	add_contact(void);
		void	view_contacts(void) const;
		void	search(void) const;
};

#endif