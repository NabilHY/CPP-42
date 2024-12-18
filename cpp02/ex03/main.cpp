/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:24:37 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/11 19:42:33 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Fixed.hpp"
#include "./include/Point.hpp"
#include <iostream>

/* For a triangle defined as (0.0) (5.0) (0.5) */
/* a: (2,2)  b: (6.6)*/

int main( void ) {
    Point const p(4.50000000001f, 0.50000000001f);
    Point const a(0, 0);
    Point const b(5, 0);
    Point const c(0, 5);
    std::cout << " the Point is " << (bsp(a, b, c, p) ? ("Inside") : ("Outside")) << std::endl;
};

/*
    Test Point 1 (2.53906, 2.53906): Outside | Expected: Inside
    Test Point 2 (4.89844, 5): Outside | Expected: Outside
    Test Point 3 (2, 2): Outside | Expected: Inside
    Test Point 4 (5, 0): Outside | Expected: On the Edge
    Test Point 5 (0, 0): Outside | Expected: On the Vertex
    Test Point 6 (-1, -1): Outside | Expected: Outside
    Test Point 7 (2.5, 1): Outside | Expected: Inside
    Test Point 8 (3, 3): Outside | Expected: Inside
    Test Point 9 (6, 6): Outside | Expected: Outside
*/