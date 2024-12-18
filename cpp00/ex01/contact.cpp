/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:16:05 by nhayoun           #+#    #+#             */
/*   Updated: 2024/09/30 15:57:55 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "contact.hpp"

Contact::Contact(){
	Index = 0;
	First_name = "";
	Last_name = "";
	Nickname = "";
	Phone_number = "";
	Darkest_secret = "";
}

Contact::Contact(int i, std::string fn, std::string ln, std::string nn,
	std::string pn, std::string ds)
{
	Index = i;
	First_name = fn;
	Last_name = ln;
	Nickname = nn;
	Phone_number = pn;
	Darkest_secret = ds;
}

std::string Contact::get_fn()
{
	return (First_name);
}
void	Contact::set_fn(std::string fn)
{
	First_name = fn;
}
std::string Contact::get_ln()
{
	return (Last_name);
}
void	Contact::set_ln(std::string ln)
{
	Last_name = ln;
}
std::string Contact::get_nn()
{
	return (Nickname);
}
void	Contact::set_nn(std::string nn)
{
	Nickname = nn;
}
std::string Contact::get_pn()
{
	return (Phone_number);
}
void	Contact::set_pn(std::string pn)
{
	Phone_number = pn;
}
std::string Contact::get_ds()
{
	return (Darkest_secret);
}
void	Contact::set_ds(std::string ds)
{
	Darkest_secret = ds;
}