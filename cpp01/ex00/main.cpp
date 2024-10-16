/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:13:46 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/16 13:39:46 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(){
	Zombie *Zp1 = new Zombie("Musolini");
	Zp1->announce();
	delete Zp1;
	randomChump("Stalin");
	return (0);
}