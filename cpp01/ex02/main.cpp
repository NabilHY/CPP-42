/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:53:20 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/17 14:57:53 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "String Variable Address : " << &str << std::endl;
	std::cout << "Address held in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held in stringREF: " << &stringREF << std::endl;
	std::cout << "String Variable Value : " << str << std::endl;
	std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF : " << stringREF << std::endl;
}
