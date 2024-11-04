/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:50 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/31 21:55:14 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
}

HumanB::~HumanB(){};

std::string HumanB::get_name()
{
	return (this->name);
}

void HumanB::set_name(std::string new_name)
{
	this->name = new_name;
}

void HumanB::attack()
{
	std::cout << this->get_name() << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
