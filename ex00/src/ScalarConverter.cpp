/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:39:02 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/01 20:41:20 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
	std::cout << "ScalarConverter default copy constructor called." << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &value)
{
	(void)value;
	std::cout << "ScalarConverter assigment operator called." << std::endl;

	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}


int	isChar(std::string lit)
{
	char charLit;
	
	if (lit.empty())
		return (1);
	charLit = lit[0];
	if (lit.size() > 1 || std::isdigit(charLit))
		return (1);
	return (0);
}

int	isInt(std::string lit)
{
	size_t i = 0;

	if (lit[i] == '+' || lit[i] == '-')
		i++;
	if (i == lit.length())
		return (1);
	while(i < lit.length())
	{
		if (!std::isdigit(lit[i]))
			return (1);
		i++;
	}

	return (0);
}

int	isFloat(std::string lit)
{
	size_t i = 0;

	if (lit.empty())
		return (1);
	if (lit[i] == '+' || lit[i] == '-')
		i++;
	if (lit[lit.length() - 1] != 'f')
		return (1);
	while (i < lit.length())
	{
		if (!std::isdigit(lit[i]) && lit[i] != '.' && lit[i] != 'f')
			return (1);
		i++;
	}

	return (0);
}

int	isDouble(std::string lit)
{
	size_t i = 0;

	if (lit.empty())
		return (1);
	if (lit[i] == '+' || lit[i] == '-')
		i++;
	while (i < lit.length())
	{
		if (!std::isdigit(lit[i]) && lit[i] != '.')
			return (1);
		i++;
	}

	return (0);
}

int	detector(std::string lit)
{
	if (!isChar(lit))
		std::cout << "CHAR" << std::endl;
	else if (!isInt(lit))
		std::cout << "INT" << std::endl;
	else if (!isFloat(lit))
		std::cout << "FLOAT" << std::endl;
	else if (!isDouble(lit))
		std::cout << "DOUBLE" << std::endl;
	else
		return (1);
	return (0);
}

void ScalarConverter::convert(std::string lit)
{
	if (!detector(lit))
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "BAD" << std::endl;

}