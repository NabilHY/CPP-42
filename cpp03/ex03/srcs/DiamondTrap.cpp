/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:10:58 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/23 14:12:27 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), Name("Stupid DiamondTrap") { std::cout << "DiamondTrap Default Constructor\n" };

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
        this->Name = name;
        this->HitPoints = FragTrap::HitPoints;
        this->EnergyPoints = ScavTrap::EnergyPoints;
        this->AttackDamage = FragTrap::AttackDamage;
};

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap Outta Here\n";
};

DiamondTrap::DiamondTrap(const DiamondTrap &ref) 
    : ClapTrap(ref), ScavTrap(ref), FragTrap(ref) {
    this->Name = ref.Name;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& ref){
    if (this != &ref){
        this->Name = ref.Name;
        this->HitPoints = ref.HitPoints;
        this->EnergyPoints = ref.EnergyPoints;
        this->AttackDamage = ref.AttackDamage;
    }
    return *this;
};

void    DiamondTrap::attack(const std::string &name)
{
    ScavTrap::attack(name);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I'm A Diamond Trap and my name is " << this->Name << std::endl;
    std::cout << "And my ClapTap name is " << ClapTrap::Name << std::endl;
}