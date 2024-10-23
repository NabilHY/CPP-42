/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:13:24 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/23 13:29:08 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
}
