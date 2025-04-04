/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:10:13 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/12 13:30:50 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"
#include <cmath>

float   absolute(float a){return (a < 0) ? -a : a;};
float   opera(float a, float b, float c) { return a * (b - c);};
Point::Point (): x(0), y(0){};
Point::Point (const float a, const float b): x(a), y(b){};
Point::~Point (){};
Point::Point (const Point &ref) : x(ref.x), y(ref.y){};
Point& Point::operator = (const Point &ref) { (void)ref ;return *this;};
float Point::getX() const { return x.toFloat(); };
float Point::getY() const { return y.toFloat(); };

float area(const Point &p1, const Point &p2, const Point &p3) {
    return 0.5 * absolute(
        opera(p1.getX(), p2.getY() , p3.getY())+
        opera(p2.getX(), p3.getY() , p1.getY())+
        opera(p3.getX(), p1.getY() , p2.getY())
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point){return  (area(a, b, c) == (area(point, a, b) + area(point, b, c) + area(point, c, a)) ? true : false);}
