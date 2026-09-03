/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:39:02 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/03 23:03:12 by cacortes         ###   ########.fr       */
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


int	charConv(std::string lit, resultPrint &result);
int	intConv(std::string lit, resultPrint &result);
int	fltConv(std::string lit, resultPrint &result);
int	dblConv(std::string lit, resultPrint &result);

int	charConv(std::string lit, resultPrint &result)
{
	char	c;
	(void)result;
	char	*end;
	
	c = static_cast<char>(lit[0]);

	if (!std::isprint(c))
	{
		std::cout << "FLAG" << std::endl;
		c = '\0';
	}

	if (std::isdigit(lit[0]))
	{
		double value = std::strtod(lit.c_str(), &end);
		if (value < 0 || value > 127)
			return (1);
		result.chr = static_cast<char>(value);
    	return (0);
	}
	result.chr = c;
	
	std::cout << "Char conversion done." << std::endl;

	return (0);
}

int	isChar(std::string lit, resultPrint &result)
{
	char charLit;
	
	if (lit.empty())
		return (1);
	charLit = lit[0];
	if (lit.size() > 1 || std::isdigit(charLit))
		return (1);

	charConv(lit, result);
	if (intConv(lit, result))
		return (1);
	if (fltConv(lit, result))
		return (1);
	if (dblConv(lit, result))
		return (1);
	
	return (0);
}


int	intConv(std::string lit, resultPrint &result)
{
	char	*end;
	long	n;
	(void)result;

	n = std::strtol(lit.c_str(), &end, 10);
	
	if (n < INT_MIN || n > INT_MAX)
		return (1);

	result.in = static_cast<int>(n);
	
	std::cout << "Int conversion done." << std::endl;

	return (0);
}

int	isInt(std::string lit, resultPrint &result)
{
	size_t i = 0;

	if (lit.empty())
		return (1);
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
	if (intConv(lit, result))
		return (1);
	if (charConv(lit, result))
		return (1);
	if (fltConv(lit, result))
		return (1);
	if (dblConv(lit, result))
		return (1);

	return (0);
}


int	fltConv(std::string lit, resultPrint &result)
{
	char	*end;
	float	n;
	(void)result;

	n = std::strtof(lit.c_str(), &end);
	
	if (n < INT_MIN || n > INT_MAX)
		return (1);

	result.flt = static_cast<float>(n);
	
	std::cout << "Float conversion done." << std::endl;

	return (0);
}

int	isFloat(std::string lit, resultPrint &result)
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
	if (fltConv(lit, result))
		return (1);
	if (charConv(lit, result))
		return (1);
	if (intConv(lit, result))
		return (1);
	if (dblConv(lit, result))
		return (1);
	return (0);
}


int	dblConv(std::string lit, resultPrint &result)
{
	char	*end;
	double	n;
	(void)result;

	n = std::strtod(lit.c_str(), &end);
	
	if (n < INT_MIN || n > INT_MAX)
		return (1);

	result.dbl = static_cast<double>(n);
	
	std::cout << "Double conversion done." << std::endl;

	return (0);
}


int	pseudo_detectors(std::string lit)
{
	if (lit == "+inf" || lit == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (1);
	}
	else if (lit == "-inf" || lit == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	}
	else if (lit == "nan" || lit == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}
	else
		return (0);
}

int	isDouble(std::string lit, resultPrint &result)
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
		if ((!std::isdigit(lit[i]) && lit[i] != '.'))
			return (1);

		i++;
	}
	if (p != 1)
		return (1);
	if (dblConv(lit, result))
		return (1);
	if (charConv(lit, result))
		return (1);
	if (intConv(lit, result))
		return (1);
	if (fltConv(lit, result))
		return (1);
	return (0);
}

void	result_printer(resultPrint result)
{
	if (result.chr == '\0')
		std::cout << "CHAR result: Non displayable" << std::endl;
	else
		std::cout << "CHAR result: " << result.chr << std::endl;
	std::cout << "INT result: " << result.in << std::endl;
	std::cout << "FLOAT result: " << std::fixed << std::setprecision(1)
				<< result.flt << "f" << std::endl;
	std::cout << "DOUBLE result: " << std::fixed << std::setprecision(1)
				<< result.dbl << std::endl;
}
int	detector(std::string lit, resultPrint &result)
{
	if (!isChar(lit, result))
		std::cout << "CHAR" << std::endl;
	else if (!isInt(lit, result))
		std::cout << "INT" << std::endl;
	else if (!isFloat(lit, result))
		std::cout << "FLOAT" << std::endl;
	else if (!isDouble(lit, result))
		std::cout << "DOUBLE" << std::endl;
	else
		return (1);

	return (0);
}

void ScalarConverter::convert(std::string lit, resultPrint result)
{
	if (pseudo_detectors(lit))
		return ;
	if (detector(lit, result))
		std::cout << "BAD\n" << std::endl;
	else
	{
		std::cout << "GOOD\n" << std::endl;
		result_printer(result);
	}

}