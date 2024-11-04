/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:53 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/31 22:26:30 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	this->weapon = weapon;
}

HumanA::~HumanA()
{
}

std::string const HumanA::get_name() const
{
	return (this->name);
}

void HumanA::set_name(std::string new_name)
{
	this->name = new_name;
}

void HumanA::attack()
{
	std::cout << this->get_name() << " attacks with their " << this->weapon.getType() << std::endl;
}
