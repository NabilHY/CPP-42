/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:53:57 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/10 13:45:52 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed() : FixVal(0.0){
    std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(const int newVal) {
    FixVal = (newVal << literal);
    std::cout << "Int constructor called!" << std::endl;
}

Fixed::Fixed(const float newVal){
    std::cout << "Float constructor called!" << std::endl;
    FixVal = static_cast<int>(roundf((newVal) * (1 << literal)));
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

void Fixed::setRawBits(int const raw){
    FixVal = raw;
}

float   Fixed::toFloat(void) const{
    return (static_cast<float>(FixVal) / (1 << literal));
}

int   Fixed::toInt(void) const{
    return (FixVal >> literal);
}

int Fixed::getRawBits() const{
    // std::cout << "getRawBits member function called" << std::endl;
    return (FixVal);
}

std::ostream& operator << (std::ostream &COUT, const Fixed& ref) {
    COUT << ref.toFloat();
    return COUT;
}

/* Arithmetic Operators */

float Fixed::operator *(const Fixed &ref) const 
{
    return (this->toFloat() * ref.toFloat());
}

float Fixed::operator +(const Fixed &ref) const 
{
    return (this->toFloat() + ref.toFloat());
}

float Fixed::operator -(const Fixed &ref) const 
{
    return (this->toFloat() - ref.toFloat());
}

float Fixed::operator /(const Fixed &ref) const 
{
    return (this->toFloat() / ref.toFloat());
}

/* Comparison Operators */ 

bool Fixed::operator >(const Fixed &ref) const 
{
    return (this->toFloat() > ref.toFloat());
}

bool Fixed::operator <(const Fixed &ref) const 
{
    return (this->toFloat() < ref.toFloat());
}

bool Fixed::operator <=(const Fixed &ref) const 
{
    return (this->toFloat() <= ref.toFloat());
}

bool Fixed::operator >=(const Fixed &ref) const 
{
    return (this->toFloat() >= ref.toFloat());
}

bool Fixed::operator ==(const Fixed &ref) const 
{
    return (this->toFloat() == ref.toFloat());
}

bool Fixed::operator !=(const Fixed &ref) const 
{
    return (this->toFloat() != ref.toFloat());
}

/* Increment/Decrement Operators */
    /* To allow the compiler to differentiate the post from pre 
        the post increment operator is overloaded with an 
        extra int parameter*/

float Fixed::operator++()
{
    FixVal++;
    return (this->toFloat());
}

float Fixed::operator--()
{
    FixVal--;
    return (this->toFloat());
}

float Fixed::operator++(int)
{
    Fixed copy;
    copy = *this;
    FixVal++;
    return (copy.toFloat());
}

float Fixed::operator--(int)
{
    Fixed copy;
    copy = *this;
    FixVal--;
    return (this->toFloat());
}

const Fixed&  Fixed::min(const Fixed &first, const Fixed &second)
{
    if (first.FixVal < second.FixVal)
        return first;
    return second;
}

const Fixed &Fixed::min(Fixed& first, Fixed& second)
{
    if (first.FixVal < second.FixVal)
        return first;
    return second;
}

const Fixed&  Fixed::max(const Fixed &first, const Fixed &second)
{
    if (first.FixVal > second.FixVal)
        return first;
    return second;
}

const Fixed &Fixed::max(Fixed& first, Fixed& second)
{
        if (first.FixVal > second.FixVal)
        return first;
    return second;
}