/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/01/07 10:12:20 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap boulbi( "Boulbi" );
	DiamondTrap fousouley( boulbi );
	DiamondTrap fousousousouley("bourskoulbi");

	boulbi.whoAmI();
	fousouley.whoAmI();
	fousousousouley = boulbi;
	fousousousouley.whoAmI();

	boulbi.attack( "black goku" );
	boulbi.takeDamage( 10 );
	boulbi.beRepaired( 10 );

	return (0);
}