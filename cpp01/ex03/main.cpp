/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:45 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/31 21:56:04 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/HumanA.hpp"
#include "include/HumanB.hpp"

int	main(void)
{
	Weapon	club;

	{
		club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
