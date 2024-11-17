/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:15:24 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/16 20:38:45 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../include/ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(const std::string &name);
        void   attack(const std::string &target) {
            std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " Points of damage\n";
        }
        void    guardGate(void);
};

#endif