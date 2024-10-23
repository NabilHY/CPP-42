/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:13:24 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/23 16:05:16 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	std::string lvl;

	if (ac == 2)
	{
		harl.complain(av[1]);
	}
	else
		std::cout << "Harl is switched off!" << std::endl;
}
