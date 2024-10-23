/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:13:00 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/23 13:22:33 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	this->options[0] = "DEBUG";
	this->options[1] = "INFO";
	this->options[2] = "WARNING";
	this->options[3] = "ERROR";
	this->levels[0] = &Harl::debug;
	this->levels[1] = &Harl::info;
	this->levels[2] = &Harl::warning;
	this->levels[3] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == options[i])
		{
			(this->*levels[i])();
			return;
		}
	}
}
