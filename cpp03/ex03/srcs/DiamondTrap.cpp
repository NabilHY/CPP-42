/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:10:58 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/24 16:40:08 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), Name("Stupid DiamondTrap") {
        std::cout << "DiamondTrap Default Constructor\n"; 
        this->HitPoints = FragTrap::HitPoints;
        this->EnergyPoints = ScavTrap::EnergyPoints;
        this->AttackDamage = FragTrap::AttackDamage;
};

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name), ScavTrap(name), FragTrap(name) {
        std::cout << "DiamondTrap Parameterized Constructor\n";
        ClapTrap::Name = name + "_clap_name";
        this->Name = name;
        this->HitPoints = FragTrap::HitPoints;
        this->EnergyPoints = ScavTrap::EnergyPoints;
        this->AttackDamage = FragTrap::AttackDamage;
};

DiamondTrap::~DiamondTrap(){std::cout << "DiamondTrap Deconstructor\n";};

DiamondTrap::DiamondTrap(const DiamondTrap &ref)
    : ClapTrap(ref.Name + "_clap_name"), ScavTrap(ref.Name), FragTrap(ref.Name) {
    std::cout << "DiamondTrap Copy Constuctor\n";
    this->Name = ref.Name;
    ClapTrap::Name = ref.ClapTrap::Name;
    this->HitPoints = ref.FragTrap::HitPoints;
    this->EnergyPoints = ref.ScavTrap::EnergyPoints;
    this->AttackDamage = ref.FragTrap::AttackDamage;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& ref){
    std::cout << "DiamondTrap Copy Assignment Operator";
    if (this != &ref) {
        ClapTrap::Name = ref.ClapTrap::Name;
        this->Name = ref.Name;
        this->HitPoints = ref.HitPoints;
        this->EnergyPoints = ref.EnergyPoints;
        this->AttackDamage = ref.AttackDamage;
    }
    return *this;
};

void    DiamondTrap::attack(const std::string &name) { ScavTrap::attack(name); }

void    DiamondTrap::whoAmI()
{
    std::cout << "I'm A Diamond Trap and my name is " << this->Name << std::endl;
    std::cout << "And my ClapTap name is " << ClapTrap::Name << std::endl;
}