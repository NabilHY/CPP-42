/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:58:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/01 11:09:34 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class Phonebook
{
private:
	static int Index;
	Contact Contacts[8];
public:
	void row_top();
	std::string get_trunc(std::string &str);
	void display_info(int index, std::string fn, std::string ln, std::string nn,
		std::string ds);
	void add(Contact *contacts, int *index);
	void display_menu(void);
	void display_contacts(Contact *contacts, int count);
};

#endif