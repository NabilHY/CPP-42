/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:12:56 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/23 13:15:02 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Harl
{
  private:
	std::string options[4];
	void (Harl::*levels[4])();
  public:
	Harl();
	~Harl();
	void debug();
	void info();
	void warning();
	void error();
	void complain(std::string level);
};
