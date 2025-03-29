/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:26:49 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/14 15:54:50 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool	is_valid(const std::string &input)
{
	if (input.empty())
		return (false);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

void	Phonebook::skip_spaces(std::string &str)
{
	str.erase(str.find_last_not_of("\n\t \r") + 1);
	str.erase(0,str.find_first_not_of("\n\t \r"));
}

void Phonebook::display_menu(void)
{
	std::cout << "\nPhonebook Menu:" << std::endl;
	std::cout << "Type :" << std::endl;
	std::cout << "ADD : Save a new contact" << std::endl;
	std::cout << "SEARCH : Display a specific contact" << std::endl;
	std::cout << "EXIT : Close the program" << std::endl;
	std::cout << "\n> ";
}

void Phonebook::display_info(int index, std::string fn, std::string ln,
	std::string nn)
{
	std::cout << std::setw(10) << index << "|" << std::setw(10) << get_trunc(fn) << "|" << std::setw(10) << get_trunc(ln) << "|" << std::setw(10) << get_trunc(nn) << "|" << std::endl;
}

void Phonebook::row_top(void)
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
	std::cout << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
}

std::string Phonebook::get_trunc(std::string &str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str[8] = '.';
	}
	return (str);
}

void Phonebook::display_contacts(Contact *contacts, int count)
{
	int		i;
	Contact	*contact;

	i = 0;
	while (i < count)
	{
		contact = contacts + i;
		display_info(i, contact->get_fn(), contact->get_ln(),
			contact->get_nn());
		i++;
	}
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
	std::cout << std::endl;
}


void Phonebook::get_input(std::string type, Contact *contacts, int index)
{
	std::string input;
	while (!std::cin.eof())
	{
		std::cout << type << ": ";
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Invalid Input\n";
			continue ;
		}
		else
		{
			skip_spaces(input);
			if (input.empty())
			{
				std::cout << "Empty Input !\n";
				continue ;
			}
			if (type == "First Name")
				contacts[index].set_fn(input);
			else if (type == "Last Name")
				contacts[index].set_ln(input);
			else if (type == "Nickname")
				contacts[index].set_nn(input);
			else if (type == "Phone Number")
				contacts[index].set_pn(input);
			else if (type == "Darkest Secret")
				contacts[index].set_ds(input);
			return ;
		}
	}
	std::cout << "End of file, Exiting program\n";
	exit(1);
}

void Phonebook::add(Contact *contacts, int *index)
{
	if (*index == 8)
		*index = 0;    
	get_input("First Name", contacts, *index);
	get_input("Last Name", contacts, *index);
	get_input("Nickname", contacts, *index);
	get_input("Phone Number", contacts, *index);
	get_input("Darkest Secret", contacts, *index);
	(*index)++;
	std::cout << " +++ Contact Added Successfully +++\n";
}

void Phonebook::contact_index(Contact *contacts, int count)
{
	int	i;

	std::string index;
	while (!std::cin.eof())
	{
		std::cout << "Enter a valid index: ";
		std::getline(std::cin, index);
		i = std::atoi(index.c_str());
		if (is_valid(index) && i < count)
		{
			std::cout << "-------------------" << std::endl;
			std::cout << "First Name: " << contacts[i].get_fn() << std::endl;
			std::cout << "Last Name: " << contacts[i].get_ln() << std::endl;
			std::cout << "Nickname: " << contacts[i].get_nn() << std::endl;
			std::cout << "Phone Number: " << contacts[i].get_pn() << std::endl;
			std::cout << "Darkest Secret: " << contacts[i].get_ds() << std::endl;
			std::cout << "-------------------" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid Index, Try again.\n";
	}
}

int	main(void)
{
	int index;
	int count;
	Contact contacts[8];
	Phonebook phonebook;
	std::string choice;

	index = 0;
	count = 0;
	choice = "string";
	while (1)
	{
		phonebook.display_menu();
		std::getline(std::cin, choice);
		if (std::cin.eof())
		{
			std::cout << "End of file, Exiting program\n";
			exit(1);
		}
		if (choice == "ADD")
		{
			phonebook.add(contacts, &index);
			if (count < 8)
				count++;
		}
		else if (choice == "SEARCH")
		{
			if (!count)
			{
				std::cout << "----------------------\n"
							<< "No Contacts Available\n"
							<< "----------------------\n"
							<< std::endl;
				continue ;
			}
			else
			{
				phonebook.row_top();
				phonebook.display_contacts(contacts, count);
				phonebook.contact_index(contacts, count);
			}
		}
		else if (choice == "EXIT")
		{
			std::cout << "Exiting Program\n";
			break ;
		}
		else
		{
			std::cout << "\n\t ++ Invalid Option ++\n" << std::endl;
		}
	}
	return (0);
}