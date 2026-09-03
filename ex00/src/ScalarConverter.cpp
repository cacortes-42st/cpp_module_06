/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:39:02 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/03 14:37:56 by cacortes         ###   ########.fr       */
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



int	charConv(std::string lit, resultPrint result)
{
	char	c;
	(void)result;
	
	c = lit[0];
	result.chr = c;
	
	std::cout << "Char conversion done." << std::endl;

	return (0);
}

int	isChar(std::string lit, resultPrint result)
{
	char charLit;
	
	if (lit.empty())
		return (1);
	charLit = lit[0];
	if (lit.size() > 1 || std::isdigit(charLit))
		return (1);

	charConv(lit, result);
	return (0);
}

int	intConv(std::string lit, resultPrint result)
{
	int	n;
	(void)result;
	
	n = std::atoi(lit[0]);

	if (n < INT_MIN && n > INT_MAX || n == 0)
		return (1);

	result.in = n;
	
	std::cout << "Int conversion done." << std::endl;

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
	int	f = 0;
	int	p = 0;

	if (lit.empty())
		return (1);
	if (lit[i] == '+' || lit[i] == '-')
		i++;
	if (lit[lit.length() - 1] != 'f')
		return (1);
	while (i < lit.length())
	{
		if (lit[i] == 'f')
			f++;
		if (lit[i] == '.')
		{
			p++;
			if (lit[i + 1] == 'f')
				return (1);
		}
		if ((!std::isdigit(lit[i]) && lit[i] != '.' && lit[i] != 'f') || f > 1 || p > 1)
			return (1);
		i++;
	}

	return (0);
}

int	isDouble(std::string lit)
{
	size_t i = 0;
	int	p = 0;

	if (lit.empty())
		return (1);
	if (lit[i] == '+' || lit[i] == '-')
		i++;
	while (i < lit.length())
	{
		if (lit[i] == '.')
		{
			p++;
			if (lit[i + 1] == 'f' || !std::isdigit(lit[i + 1]) || !std::isdigit(lit[i - 1]))
				return (1);
		}
		if ((!std::isdigit(lit[i]) && lit[i] != '.') || p > 1)
			return (1);
		i++;
	}

	return (0);
}

int	detector(std::string lit, resultPrint result)
{
	if (!isChar(lit, result))
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

void ScalarConverter::convert(std::string lit, resultPrint result)
{
	if (!detector(lit, result))
		std::cout << "GOOD" << std::endl;
	else
		std::cout << "BAD" << std::endl;

}