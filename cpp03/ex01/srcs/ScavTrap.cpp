/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:48:10 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/20 02:31:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {};

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {HitPoints = 100;EnergyPoints = 50;AttackDamage = 20; guarding = false; std::cout << "ScavTrap Created\n"; };

ScavTrap::~ScavTrap() {std::cout << "ScavTrap Outta here\n";};

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref.Name) { HitPoints = ref.HitPoints; EnergyPoints = ref.EnergyPoints; AttackDamage = ref.AttackDamage; };

ScavTrap& ScavTrap::operator=(const ScavTrap& ref){ std::cout << "Assignment Operator\n"; if (this == &ref) return *this; ClapTrap::operator=(ref); this->Name = ref.Name; this->HitPoints = ref.HitPoints; this->EnergyPoints = ref.EnergyPoints; this->AttackDamage = ref.AttackDamage; return *this;};

void    ScavTrap::attack(const std::string &target) {
    std::cout << "=== ATTACK ===" << std::endl;
    if (this->HitPoints <= 0) std::cout << this->Name << " cannot attack because he's Finished!" << std::endl;
    else if (this->EnergyPoints <= 0) std::cout << this->Name << " cannot attack because it has no energy points left!" << std::endl;
    else if (this->AttackDamage <= 0) std::cout << this->Name << " cannot attack because its attack damage is zero!" << std::endl;
    else {this->EnergyPoints--;std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;}
}

void ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "=== TAKING DAMAGE ===" << std::endl;
    if (!this->HitPoints) { std::cout << this->Name << " is already finished and can't take more damage." << std::endl; return;};
    unsigned int damage = (amount <= this->HitPoints) ? amount : this->HitPoints;
    this->HitPoints -= damage;
    std::cout << this->Name << " lost " << damage << " Hit Points!" << std::endl;
    if (this->HitPoints == 0) {std::cout << this->Name << " is finished." << std::endl;}
}

void ScavTrap::beRepaired(unsigned int amount) {
    std::cout << "=== REPAIR ===" << std::endl;
    if (this->HitPoints == 0) { std::cout << "ScavTrap can't be repaired, it's finished!" << std::endl; return;};
    if (this->EnergyPoints == 0) { std::cout << "No energy points left! Can't repair!" << std::endl;return;};
    const unsigned int maxHitPoints = 100;
    unsigned int recovered = (this->HitPoints + amount > maxHitPoints) ? (maxHitPoints - this->HitPoints) : amount;
    this->HitPoints += recovered;
    this->EnergyPoints -= 1;
    std::cout << "ScavTrap recovered " << recovered << " hit points!" << std::endl;
    std::cout << this->Name << " now has " << this->HitPoints << " hit points and " << this->EnergyPoints << " energy points remaining." << std::endl;
}

void ScavTrap::guardGate(){ if (this->guarding)  std::cout << "ScavTrap is already in Gate Guarding mode\n"; else {this->guarding = true; std::cout << "ScavTrap Switched to gate guarding mode\n";}};
