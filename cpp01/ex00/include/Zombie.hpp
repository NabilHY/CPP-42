/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:14:11 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/16 13:50:24 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

void randomChump(std::string name);

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		~Zombie(void);
		Zombie(std::string name);
		void announce(void);
		std::string get_name();
		void set_name(std::string name);
};


#endif