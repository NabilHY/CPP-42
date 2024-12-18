/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:39:39 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/17 16:06:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
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

Zombie	*zombieHorde(int N, std::string name);

#endif
