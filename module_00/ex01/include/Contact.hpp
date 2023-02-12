/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 02:26:38 by auzun             #+#    #+#             */
/*   Updated: 2023/01/02 19:28:32 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
	int	index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	std::string	trunc(std::string str) const;
	std::string	get_input(std::string str) const;
	
public:
	Contact();
	~Contact();
	void		set_atr(int index);
	void		set_index(int index);
	void		view(void) const;
	void		display(void) const;
};

#endif
