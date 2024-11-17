/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/16 14:48:53 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ClapTrap.hpp"

int main() {
    ClapTrap autobot("Optimus Prime");
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