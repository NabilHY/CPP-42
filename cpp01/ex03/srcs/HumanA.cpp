/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:53 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/19 18:12:56 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{this->weapon = weapon;
}

HumanA::~HumanA()
{
}

std::string HumanA::get_name()
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
