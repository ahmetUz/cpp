/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:28:14 by auzun             #+#    #+#             */
/*   Updated: 2023/01/07 09:16:10 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void )
{
	FragTrap boulbi( "BOULBI" );
	FragTrap fousouley( boulbi );

	boulbi.attack( "Boulbabilone" );
	boulbi.takeDamage( 10 );
	boulbi.beRepaired( 10 );
	boulbi.highFivesGuys();

	return (0);
}