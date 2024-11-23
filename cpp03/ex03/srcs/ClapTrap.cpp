/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:22 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/23 12:24:32 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(""), HitPoints(10), EnergyPoints(10), AttackDamage(0) {std::cout << "Stupid ClapTrap Created\n";};

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) { std::cout << "ClapTrap Created\n"; };

ClapTrap::~ClapTrap(){ std::cout << "ClapTrap Outta here!\n"; };

ClapTrap::ClapTrap(const ClapTrap &ref)
    : Name(ref.Name), HitPoints(ref.HitPoints), EnergyPoints(ref.EnergyPoints), AttackDamage(ref.AttackDamage){};

ClapTrap &ClapTrap::operator = (const ClapTrap &ref){if (this != &ref){this->Name = ref.Name; this->HitPoints = ref.HitPoints; this->EnergyPoints = ref.EnergyPoints; this->AttackDamage = ref.AttackDamage;} return *this;};

void    ClapTrap::attack(const std::string &target) {
    std::cout << "=== ATTACK ===" << std::endl;
    if (this->HitPoints <= 0) std::cout << this->Name << " cannot attack because he's Finished!" << std::endl;
    else if (this->EnergyPoints <= 0) std::cout << this->Name << " cannot attack because it has no energy points left!" << std::endl;
    else if (this->AttackDamage <= 0) std::cout << this->Name << " cannot attack because its attack damage is zero!" << std::endl;
    else {this->EnergyPoints--;std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;}
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "=== TAKING DAMAGE ===" << std::endl;
    if (!this->HitPoints) { std::cout << this->Name << " is already finished and can't take more damage." << std::endl; return;};
    unsigned int damage = (amount <= this->HitPoints) ? amount : this->HitPoints;
    this->HitPoints -= damage;
    std::cout << this->Name << " lost " << damage << " Hit Points!" << std::endl;
    if (this->HitPoints == 0) {std::cout << this->Name << " is finished." << std::endl;}
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "=== REPAIR ===" << std::endl;
    if (this->HitPoints == 0) { std::cout << "ClapTrap can't be repaired, it's finished!" << std::endl; return;};
    if (this->EnergyPoints == 0) { std::cout << "No energy points left! Can't repair!" << std::endl;return;};
    const unsigned int maxHitPoints = 10;
    unsigned int recovered = (this->HitPoints + amount > maxHitPoints) ? (maxHitPoints - this->HitPoints) : amount;
    this->HitPoints += recovered;
    this->EnergyPoints -= 1;
    std::cout << "ClapTrap recovered " << recovered << " hit points!" << std::endl;
    std::cout << this->Name << " now has " << this->HitPoints << " hit points and " << this->EnergyPoints << " energy points remaining." << std::endl;
}