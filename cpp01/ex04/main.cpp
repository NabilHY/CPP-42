/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:14:07 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/19 19:53:25 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(void)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::cout << "Filename: ";
	std::getline(std::cin, filename);
	std::ifstream file(filename);
	if (!file.is_open())
		std::cout << "file not found" << std::endl;
	else
	{
		std::cout << "file open" << std::endl;
		std::string newfile = filename + ".replace";
		std::ofstream outfile(newfile);
		if (!outfile.is_open())
		{
			std::cout << "File not open" << std::endl;
			return (1);
		}
		else
		{
			std::cout << "First string: ";
			std::getline(std::cin, s1);
			std::cout << "Second string: ";
			std::getline(std::cin, s2);
			while (std::getline(file, line))
			{
				
				outfile << line << "\n";
			}
			outfile.close();
			std::ifstream newinfile(newfile);
			while (std::getline(newinfile, line))
			{
				// detect string 1 in line and replace i with string 2

			}
			newinfile.close();
		}
	}
	return (1);
}
