/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:15:24 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/22 13:27:49 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    private:
        bool guarding;
    public:
        ScavTrap();
        ScavTrap(const std::string &);
        ~ScavTrap();
        ScavTrap(const ScavTrap &);
        ScavTrap& operator = (const ScavTrap &);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    guardGate(void);
        void    attack(const std::string &target);
};

#endif