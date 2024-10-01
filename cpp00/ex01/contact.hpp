/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:16:25 by nhayoun           #+#    #+#             */
/*   Updated: 2024/10/01 11:09:22 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include  <string>

class Contact
{
private:
	int Index;
	std::string First_name;
	std::string Last_name;
	std::string Nickname;
	std::string Phone_number;
	std::string Darkest_secret;
public:
	Contact();
	Contact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	std::string get_fn();
	void set_fn(std::string fn);
	std::string get_ln();
	void set_ln(std::string ln);
	std::string get_nn();
	void set_nn(std::string nn);
	std::string get_pn();
	void set_pn(std::string pn);
	std::string get_ds();
	void set_ds(std::string ds);
};

#endif
