/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:13:00 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/23 16:15:17 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl()
{
	this->options[0] = "DEBUG";
	this->options[1] = "INFO";
	this->options[2] = "WARNING";
	this->options[3] = "ERROR";
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	int lvl;

	lvl = 4;
	for (int i = 0; i < 4; i++)
		if (options[i] == level)
			lvl = i;
	for (int j = lvl; j <= 4; j++)
	{
		switch (j)
		{
			case 0:
				std::cout << "[ " + options[j] + " ]" << std::endl;
				std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
				break;
			case 1:
				std::cout << "[ " + options[j] + " ]" << std::endl;
				std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did,  I wouldn't be asking for more!" << std::endl;
				break;
			case 2:
				std::cout << "[ " + options[j] + " ]" << std::endl;
				std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
				break;
			case 3:
				std::cout << "[ " + options[j] + " ]" << std::endl;
				std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]"<< std::endl;
				break;
		}
	}
}
