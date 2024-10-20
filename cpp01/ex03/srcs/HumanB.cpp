/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:50 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/19 11:14:49 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	this->weapon = nullptr;
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
