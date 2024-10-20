/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:18:03 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/19 13:13:21 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	  ~HumanA();
	  HumanA(std::string name, Weapon &weapon);
	  void attack();
	  std::string get_name();
	  void set_name(std::string new_name);
};

#endif
