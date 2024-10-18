/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:48 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/18 15:32:05 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(){
};

Weapon::Weapon(std::string const &type)
{
	this->type = type;
};
Weapon::~Weapon(){};

const std::string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
