/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/01/06 20:54:33 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap ash( "Ash" );
	ScavTrap ash2( ash );

	ash.attack( "the air" );
	ash.takeDamage( 10 );
	ash.beRepaired( 10 );
	ash.guardGate();

	return (0);
}