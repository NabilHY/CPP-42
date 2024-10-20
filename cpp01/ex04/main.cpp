/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:14:07 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/20 18:14:57 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string replaceSubstring(const std::string &line, const std::string &str1,
	const std::string &str2)
{
	size_t	pos;
	size_t	found;

	std::string result;
	pos = 0;
	while ((found = line.find(str1, pos)) != std::string::npos)
	{
		result.append(line, pos, found - pos);
		result.append(str2);
		pos = found + str1.length();
	}
	result.append(line, pos, line.length() - pos);
	return (result);
}

int	main(void)
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::cout << "Filename: ";
	std::getline(std::cin, filename);
	std::ifstream file(filename);
	if (!file.is_open()){
		std::cout << "file not found" << std::endl;
		return (1);
	}
	else
	{
		std::cout << "file opened" << std::endl;
		std::string newfile = filename + ".replace";
		std::ofstream outfile(newfile);
		if (!outfile.is_open())
		{
			std::cout << "Failure" << std::endl;
			return (1);
		}
		else
		{
			while (s1.empty())
			{
				std::cout << "First string: ";
				std::getline(std::cin, s1);
			}
			while (s2.empty())
			{
				std::cout << "Second string: ";
				std::getline(std::cin, s2);
			}
			while (std::getline(file, line))
			{
				line = replaceSubstring(line, s1, s2);
				outfile << line << std::endl;
			}
			outfile.close();
		}
	}
	return (1);
}
