/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:48:10 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/24 13:03:32 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {std::cout << "FragTrap Default Constructor\n";};

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {HitPoints = 100;EnergyPoints = 100; AttackDamage = 30;  highFive = false; std::cout << "FragTrap Parameterized Constructor\n"; };

FragTrap::~FragTrap() {std::cout << "FragTrap Deconstructor\n";};

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref.Name) {std::cout << "FragTrap Copy Constructor\n"; HitPoints = ref.HitPoints; EnergyPoints = ref.EnergyPoints; AttackDamage = ref.AttackDamage; highFive = ref.highFive; };

FragTrap& FragTrap::operator=(const FragTrap& ref) { std::cout << "FragTrap Copy Assignment Operator\n"; if (this == &ref) return *this; ClapTrap::operator=(ref); this->Name = ref.Name; this->HitPoints = ref.HitPoints; this->EnergyPoints = ref.EnergyPoints; this->AttackDamage = ref.AttackDamage; highFive = ref.highFive; return *this;};

void    FragTrap::attack(const std::string &target) {
    std::cout << "=== ATTACK ===" << std::endl;
    if (this->HitPoints <= 0) std::cout << this->Name << " cannot attack because he's Finished!" << std::endl;
    else if (this->EnergyPoints <= 0) std::cout << this->Name << " cannot attack because it has no energy points left!" << std::endl;
    else if (this->AttackDamage <= 0) std::cout << this->Name << " cannot attack because its attack damage is zero!" << std::endl;
    else {this->EnergyPoints--;std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;}
}

void FragTrap::takeDamage(unsigned int amount) {
    std::cout << "=== TAKING DAMAGE ===" << std::endl;
    if (!this->HitPoints) { std::cout << this->Name << " is already finished and can't take more damage." << std::endl; return;};
    unsigned int damage = (amount <= this->HitPoints) ? amount : this->HitPoints;
    this->HitPoints -= damage;
    std::cout << this->Name << " lost " << damage << " Hit Points!" << std::endl;
    if (this->HitPoints == 0) {std::cout << this->Name << " is finished." << std::endl;}
}

void FragTrap::beRepaired(unsigned int amount) {
    std::cout << "=== REPAIR ===" << std::endl;
    if (this->HitPoints == 0) { std::cout << "FragTrap can't be repaired, it's finished!" << std::endl; return;};
    if (this->EnergyPoints == 0) { std::cout << "No energy points left! Can't repair!" << std::endl;return;};
    const unsigned int maxHitPoints = 100;
    unsigned int recovered = (this->HitPoints + amount > maxHitPoints) ? (maxHitPoints - this->HitPoints) : amount;
    this->HitPoints += recovered;
    this->EnergyPoints -= 1;
    std::cout << "FragTrap recovered " << recovered << " hit points!" << std::endl;
    std::cout << this->Name << " now has " << this->HitPoints << " hit points and " << this->EnergyPoints << " energy points remaining." << std::endl;
}

void FragTrap::highFivesGuys(){ if (this->highFive)  std::cout << "FragTrap has already high fived everyone\n"; else {this->highFive = true; std::cout << "FragTrap high fives all the robots \n";}};
