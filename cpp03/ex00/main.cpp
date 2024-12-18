/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/19 16:44:27 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ClapTrap.hpp"

int main() {
    ClapTrap autobot("Optimus Prime");
    autobot.takeDamage(8);
    autobot.beRepaired(4);
    autobot.beRepaired(4);
    autobot.beRepaired(1);
    autobot.takeDamage(5);
    autobot.takeDamage(2);
    autobot.beRepaired(1);
    autobot.takeDamage(5);
    autobot.attack("Magetoron");
    autobot.takeDamage(10);
    autobot.takeDamage(1);
    return 0;
}