/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:22:10 by auzun             #+#    #+#             */
/*   Updated: 2023/02/20 17:36:15 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	TYPE_HPP
# define TYPE_HPP

# include "ABC.hpp"
# include <cstdlib>

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif