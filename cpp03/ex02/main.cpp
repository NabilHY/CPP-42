/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:26 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/19 20:59:40 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main() {
    FragTrap frag1("Warrior");
    frag1.attack("EnemyBot");
    frag1.takeDamage(40);
    frag1.beRepaired(30);
    frag1.attack("EnemyBot");
    FragTrap frag2 = frag1;
    frag2.attack("AnotherEnemy");
    FragTrap frag3("TemporaryBot");
    frag3 = frag1;
    frag3.takeDamage(60);
    frag1.highFivesGuys();
    frag1.highFivesGuys();
    return 0;
}