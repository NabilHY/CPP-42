/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:10:58 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/22 15:39:39 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Creating diamondTrap
        DiamondTrap inherits both From Scav/Frag themselves inherit from Clap
    Key requirements :
        -> Name Attribute: 
            - DiamondTrap has private attribute named same as ClapTrap
            - This dual inherritace structure may lead to ambiguity or shadowing due to multiple inheritance of claptrap
*/

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), Name("Stupid DiamondTrap") {};

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

DiamondTrap::DiamondTrap(const DiamondTrap &ref){
    this->Name = ref.Name;
    this->HitPoints = ref.HitPoints;
    this->EnergyPoints = ref.EnergyPoints;
    this->AttackDamage = ref.AttackDamage;
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
}