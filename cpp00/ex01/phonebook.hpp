/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:58:19 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/13 11:28:11 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <stdlib.h>
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
	void get_input(std::string type, Contact *contacts, int index);
	void display_info(int index, std::string fn, std::string ln, std::string nn);
	void add(Contact *contacts, int *index);
	void display_menu(void);
	void display_contacts(Contact *contacts, int count);
	void contact_index(Contact *contacts, int count);
	void	skip_spaces(std::string &str);
};

#endif