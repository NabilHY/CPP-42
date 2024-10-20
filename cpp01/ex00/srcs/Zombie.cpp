/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:24:49 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/16 20:55:02 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->get_name() << ": They got a ray gun I'm Outta here\n" << std::endl;
}

std::string Zombie::get_name()
{
	return (this->name);
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

void Zombie::announce()
{
	std::cout << get_name() + ": "
				<< "BraiiiiiiinnnzzzZ..." << std::endl;
}
