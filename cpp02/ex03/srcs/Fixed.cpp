/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/11 19:04:21 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : FixVal(0.0){
    // std::cout << "Default constructor called!" << std::endl;
}
Fixed::Fixed(const int newVal) {
    FixVal = (newVal << literal);
    // std::cout << "Int constructor called!" << std::endl;
}

Fixed::Fixed(const float newVal){
    // std::cout << "Float constructor called!" << std::endl;
    FixVal = static_cast<int>(roundf((newVal) * (1 << literal)));
}

Fixed::~Fixed(){
    // std::cout << "Destructor called" << std::endl;
};

Fixed::Fixed(const Fixed &origin){
//    std::cout << "Copy constructor called" << std::endl;
    FixVal = origin.FixVal; 
}

Fixed& Fixed::operator= (const Fixed& origin) {
        // std::cout << "Copy assignment operator called" << std::endl;
        FixVal = origin.FixVal;
        return *this;
}

void    Fixed::setRawBits(int const raw){FixVal = raw;}
float   Fixed::toFloat(void) const{return (static_cast<float>(FixVal) / (1 << literal));}
int     Fixed::toInt(void) const{return (FixVal >> literal);}
int     Fixed::getRawBits() const{return (std::cout << "getRawBits member function called" << std::endl,FixVal);}

std::ostream& operator << (std::ostream &COUT, const Fixed& ref) {return (COUT << ref.toFloat(), COUT);}

/* Arithmetic Operators */

float Fixed::operator *(const Fixed &ref) const {return (this->toFloat() * ref.toFloat());}
float Fixed::operator +(const Fixed &ref) const {return (this->toFloat() + ref.toFloat());}
float Fixed::operator -(const Fixed &ref) const {return (this->toFloat() - ref.toFloat());}
float Fixed::operator /(const Fixed &ref) const {return (this->toFloat() / ref.toFloat());}
/* Comparison Operators */ 
bool Fixed::operator >(const Fixed &ref) const {return (this->toFloat() > ref.toFloat());}
bool Fixed::operator <(const Fixed &ref) const {return (this->toFloat() < ref.toFloat());}
bool Fixed::operator <=(const Fixed &ref) const {return (this->toFloat() <= ref.toFloat());}
bool Fixed::operator >=(const Fixed &ref) const {return (this->toFloat() >= ref.toFloat());}
bool Fixed::operator ==(const Fixed &ref) const {return (this->toFloat() == ref.toFloat());}
bool Fixed::operator !=(const Fixed &ref) const {return (this->toFloat() != ref.toFloat());}
/* Increment/Decrement Operators */

Fixed Fixed::operator++(){FixVal++;return (*this);}
Fixed Fixed::operator--(){FixVal--;return (*this);}
Fixed Fixed::operator++(int){Fixed copy(*this);return (operator++(),copy);}
Fixed Fixed::operator--(int){Fixed copy(*this);return (operator--(),copy);}
const Fixed&  Fixed::min(const Fixed &a, const Fixed &b) {return (a.FixVal < b.FixVal ? a : b);}
const Fixed &Fixed::min(Fixed& a, Fixed& b) {return (a.FixVal < b.FixVal ? a : b);}
const Fixed&  Fixed::max(const Fixed &a, const Fixed &b) {return (a.FixVal > b.FixVal ? a : b);}
const Fixed &Fixed::max(Fixed& a, Fixed& b) {return (a.FixVal > b.FixVal ? a : b);}