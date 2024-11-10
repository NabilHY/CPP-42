/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/09 15:39:10 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : FixVal(0){
    std::cout << "Default constructor called!" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &origin){
    std::cout << "Copy constructor called" << std::endl;
    FixVal = origin.FixVal;
}

Fixed& Fixed::operator= (const Fixed& origin) {
    std::cout << "Copy assignment operator called" << std::endl;
    FixVal = origin.FixVal;
    return *this;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return (FixVal);
}

void Fixed::setRawBits(int const raw){
    FixVal = raw;
}
