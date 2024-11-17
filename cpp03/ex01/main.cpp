/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/17 09:33:27 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ScavTrap.hpp"

int main() {
    // Create a ScavTrap object
    ScavTrap scav("Bumblebee");

    scav.attack("CREATINO");

    // scav.beRepaired(2);
    // scav.takeDamage(15);
    // scav.takeDamage(10);
    // scav.beRepaired(3);
    // scav.attack("Decepticon");
    // scav.takeDamage(50);

    // // Special ScavTrap feature
    // std::cout << "\n=== Activating Gate Keeper Mode ===" << std::endl;
    // scav.guardGate();

    // // More attacks to check energy depletion handling
    // scav.attack("Decepticon Commander");
    // scav.attack("Minion");
    // scav.takeDamage(100);  // Completely deplete hit points

    // // Attempt more actions after depletion
    // scav.attack("Final Enemy");
    // scav.beRepaired(5);

    return 0;
}