/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:14:07 by nhayoun           #+#    #+#             */
/*   Updated: 2024/11/04 11:33:23 by nhayoun          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename;
		std::string s1;
		std::string s2;
		std::string line;
	
		filename = av[1];
		s1 = av[2];
		s2 = av[3];
		std::ifstream file(filename.c_str());
		if (!file.is_open()){
			std::cout << "file not found" << std::endl;
			return (1);
		}
		else
		{
			std::string newfile = filename + ".replace";
			std::ofstream outfile(newfile.c_str());
			if (!outfile.is_open())
			{
				std::cout << "Failure" << std::endl;
				return (1);
			}
			else
			{
				while (std::getline(file, line))
				{
					if (!(s1.empty()))
					{
						line = replaceSubstring(line, s1, s2);
						outfile << line << std::endl;
					}
					else
						outfile << line << std::endl;
				}
				outfile.close();
			}
		}
		return (1);
	}
}
