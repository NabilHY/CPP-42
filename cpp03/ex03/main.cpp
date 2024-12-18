/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/24 15:53:59 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/DiamondTrap.hpp"

#include "DiamondTrap.hpp"

int main()
{
		DiamondTrap b("Giga");

		// b.whoAmI();
		// b.print();
		// b.attack("Chadd-clone");
		DiamondTrap c(b);
		std::cout << "=========\n";
		c.print();
		// std::cout << b.HitPoints << std::endl;
		// std::cout << b.EnergyPoints << std::endl;
		// std::cout << b.AttackDamage << std::endl;
	return (0);
}