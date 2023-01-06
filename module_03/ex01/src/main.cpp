/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/01/06 21:01:16 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap boulbi( "BOULBI" );
	ScavTrap fousouley( boulbi );

	boulbi.attack( "Boulbabilone" );
	boulbi.takeDamage( 10 );
	boulbi.beRepaired( 10 );
	boulbi.guardGate();

	return (0);
}