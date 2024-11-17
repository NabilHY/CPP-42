/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:22 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/17 10:09:42 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(""), HitPoints(100), EnergyPoints(50), AttackDamage(20) {std::cout << "Base Class Default const\n";};
ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(100), EnergyPoints(50), AttackDamage(20) {std::cout << "Base Class Param. const\n";};
ClapTrap::~ClapTrap(){ std::cout << "Claptrap is gone !\n" << std::endl;};
ClapTrap::ClapTrap(const ClapTrap &ref) 
    : Name(ref.Name), HitPoints(ref.HitPoints), EnergyPoints(ref.EnergyPoints), AttackDamage(ref.AttackDamage){std::cout << "Base class Copy const\n";};
ClapTrap &ClapTrap::operator = (const ClapTrap &ref){std::cout << "Base Class .. Copy Assignment\n";if (this != &ref){this->Name = ref.Name; this->HitPoints = ref.HitPoints; this->EnergyPoints = ref.EnergyPoints; this->AttackDamage = ref.AttackDamage;} return *this;};

void    ClapTrap::reduceHealth(int value){this->HitPoints -= value;};

void    ClapTrap::attack(const std::string &target) {
    std::cout << "=== ATTACK ===" << std::endl;
    if (this->HitPoints <= 0) std::cout << this->Name << " cannot attack because he's Finished!" << std::endl;
    else if (this->EnergyPoints <= 0) std::cout << this->Name << " cannot attack because it has no energy points left!" << std::endl;
    else if (this->AttackDamage <= 0) std::cout << this->Name << " cannot attack because its attack damage is zero!" << std::endl;
    else {this->EnergyPoints--;std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;}
}

void    ClapTrap::takeDamage(unsigned int amount){
    std::cout << "=== TAKING DAMAGE ===" << std::endl;
    unsigned int damage = 0;
    if (!this->HitPoints) {std::cout << this->Name << " is finished" << std::endl;return;};
    while (amount && this->HitPoints)
    {
        this->HitPoints--;
        damage++;
        amount--;
    }
    std::cout << this->Name << " lost " << damage << " Points!"  << std::endl;
};

void    ClapTrap::beRepaired(unsigned int amount){
    std::cout << "=== REPAIR ===" << std::endl;
    unsigned int points = 0;
    if (!this->HitPoints)
        std::cout << "ClaptTrap can't be repaired, he's Finished!" << std::endl;
    else if (!this->EnergyPoints)
        std::cout << " No energy points left ! Can't Repair ! " << std::endl;
    else if (this->HitPoints == 100)
        std::cout << "ClapTrap Trap has full HitPoints" << std::endl; 
    else
    {
        while (this->HitPoints++ != 100 && amount++) {points++;};
        std::cout << "ClapTrap Recovered " << points << " Points!" << std::endl;
    }
};
