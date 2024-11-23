/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/23 11:47:19 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ScavTrap.hpp"

int main() {
    
    ClapTrap *scav = new ScavTrap("scavtrap");
    /*ScavTrap scav1("Guardian");
    scav1.attack("Enemy1");
    scav1.takeDamage(80);
    scav1.beRepaired(50);
    scav1.guardGate();
    scav1.guardGate();
    ScavTrap scav2 = scav1;
    scav2.attack("Enemy2");
    ScavTrap scav3("Temporary");
    scav3 = scav1;
    scav3.takeDamage(60);*/
    delete scav;
    return 0;
}

