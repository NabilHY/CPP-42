/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:13:46 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/02 15:01:20 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./include/Zombie.hpp"

int main(){
	Zombie *Zp1 = new Zombie("Musolini");
	Zp1->announce();
	delete Zp1;
	randomChump("Stalin");
	return (0);
}