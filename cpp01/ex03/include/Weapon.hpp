/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:17:58 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/19 11:05:25 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include <utility>

class Weapon {
	private:
		std::string type;
	public :
		Weapon();
		~Weapon();
		Weapon(std::string const & type);
		const std::string & getType() ;
		void setType(std::string new_type);
};

#endif
