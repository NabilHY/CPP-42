/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:35:50 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/17 11:03:14 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Zombie.hpp"

int	main(void)
{
	Zombie *horde = zombieHorde(5, "Matadores");
	for (int i = 0; i < 5; i++){
		horde[i].announce();
	}
	delete[] horde;
	std::cout << sizeof(Zombie);
}
