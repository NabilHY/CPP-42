/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:10:29 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/22 16:57:42 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
    private:
        std::string Name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        ~DiamondTrap();
        DiamondTrap(const DiamondTrap&);
        DiamondTrap&    operator=(const DiamondTrap&);
        void    attack(const std::string &name);
        void    whoAmI();
};



#endif