/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:26:49 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/02 16:55:36 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

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

void Phonebook::add(Contact *contacts, int *index)
{
	if (*index == 8)
		*index = 0;
	std::string input;
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	contacts[*index].set_fn(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	contacts[*index].set_ln(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contacts[*index].set_nn(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	contacts[*index].set_pn(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	contacts[*index].set_ds(input);
	(*index)++;
	std::cout << " +++ Contact Added Succesefully +++\n";
}

void Phonebook::contact_index(Contact *contacts, int count)
{
	int	i;

	std::string index;
	while (1)
	{
		std::cout << "Enter a valid index: ";
		std::getline(std::cin, index);
		i = std::stoi(index);
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
	while (1)
	{
		phonebook.display_menu();
		std::getline(std::cin, choice);
		if (std::cin.eof())
		{
			std::cout << "End of file, Exiting program\n";
			break;
		}
		transform(choice.begin(), choice.end(), choice.begin(), ::toupper);
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