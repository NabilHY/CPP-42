/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:15:24 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/20 02:38:43 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../include/ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:
        bool highFive;
    public:
        FragTrap();
        FragTrap(const std::string &);
        ~FragTrap();
        FragTrap(const FragTrap &);
        FragTrap& operator = (const FragTrap &);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    highFivesGuys(void);
        void    attack(const std::string &target);
};

#endif