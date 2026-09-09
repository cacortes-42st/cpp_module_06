/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 11:39:02 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/09 11:14:29 by cacortes         ###   ########.fr       */
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
	
	long value = std::strtol(lit.c_str(), &end, 10);

	if (*end != '\0')
	{
		if (*end == '.')
		{
				if (value < 0 || value > 127)
				{
					result.MaxMinC = true;
					return (0);
				}
				if (lit[lit.length() - 1] == 'f')
				{
					float f = std::strtof(lit.c_str(), &end);
					c = static_cast<char>(f);
				}
				else
				{
					double d = std::strtod(lit.c_str(), &end);
					c = static_cast<char>(d);			
				}
				c = static_cast<char>(value);
				if (!std::isprint(static_cast<unsigned char>(c)))
				{
					result.NoPrint = true;
					return (0);
				}
		}
		else
			c = static_cast<char>(lit[0]);
		result.chr = c;
		
		return (0);
	}

	if (value < 0 || value > 127)
	{
		result.MaxMinC = true;
		return (0);
	}
	if (!std::isprint(value))
	{
		result.NoPrint = true;
		return (0);
	}
	
	if (std::isdigit(lit[0]))
	{
		double value = std::strtod(lit.c_str(), &end);
		if (value < 0 || value > 127)
		{
			result.NoPrint = true;
			return (1);
		}
		result.chr = static_cast<char>(value);
    	return (0);
	}
	else
		c = static_cast<char>(lit[0]);
	result.chr = c;	

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
	int	i = 0;

	n = std::strtol(lit.c_str(), &end, 10);
	if (n < INT_MIN || n > INT_MAX)
	{
		result.MaxMinI = true;
		return (0);
	}
	if (*end != '\0')
	{
		if (lit.length() == 1 && !std::isdigit(lit[0]))
			i = static_cast<int>(lit[0]);
		else if (lit[lit.length() - 1] == 'f')
		{
			double d = std::strtod(lit.c_str(), &end);
			if (d < INT_MIN || d > INT_MAX)
			{
				result.MaxMinI = true;
				return (0);
			}
			i = static_cast<int>(d);
		}
		else if(*end == '.')
		{
			double d = std::strtod(lit.c_str(), &end);
			if (d < INT_MIN || d > INT_MAX)
			{
				result.MaxMinI = true;
				return (0);
			}
			i = static_cast<int>(d);					
		}
	}
	else
		i = static_cast<int>(n);

	result.in = i;

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
	float f = 0;

	n = std::strtof(lit.c_str(), &end);
	
	if (*end == '\0')
	{
		double d = std::strtod(lit.c_str(), &end);
		f = static_cast<float>(d);				
	}
	else if (*end == 'f' && lit.length() == 1)
		f = static_cast<float>(*end);
	else if (*end != 'f')
	{
		if (lit.length() == 1 && !std::isdigit(lit[0]))
			f = static_cast<float>(lit[0]);
	}
	else
		f = static_cast<float>(n);
	result.flt = f;
	
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
		if (lit[i] == '.' && lit[i + 1] != '\0')
		{
			p++;
			if (lit[i + 1] == 'f')
				return (1);
		}
		if ((!std::isdigit(lit[i]) && lit[i] != '.' && lit[i] != 'f') || f > 1 || p > 1)
			return (1);
		i++;
	}
	if (p != 1)
		return (1);
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
	double d = 0;

	n = std::strtod(lit.c_str(), &end);

	if (*end != '\0')
	{
		if (!std::isdigit(lit[0]))
			d = static_cast<double>(lit[0]);
		if (*end == 'f' && lit.length() == 1)
			d = static_cast<double>(*end);
		else if (lit[lit.length() - 1] == 'f')
		{
			float f = std::strtof(lit.c_str(), &end);
			d = static_cast<double>(f);
		}
	}
	else
		d = static_cast<double>(n);
	result.dbl = d;

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
		if (lit[i] == '.' && lit[i + 1] != '\0' && lit[i - 1] != '\0')
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


void	result_printer(resultPrint result)
{
	if (result.NoPrint)
		std::cout << "char: Non displayable" << std::endl;
	else if (result.MaxMinC)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << "'" << result.chr << "'" << std::endl;
	
	if (result.MaxMinI)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << result.in << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1)
				<< result.flt << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1)
				<< result.dbl << std::endl;
}


int	detector(std::string lit, resultPrint &result)
{
	if (!isChar(lit, result))
		return (0);
	else if (!isInt(lit, result))
		return (0);
	else if (!isFloat(lit, result))
		return (0);
	else if (!isDouble(lit, result))
		return (0);
	else
		return (1);

	return (0);
}

void	initStruct(resultPrint &result)
{
	(void)result;
	result.MaxMinI = false;
	result.MaxMinC = false;
	result.NoPrint = false;
	result.chr = '\0';
	result.in = 0;
	result.flt = 0;
	result.dbl = 0;
}

void ScalarConverter::convert(std::string lit)
{
	resultPrint	result;

	initStruct(result);
	if (pseudo_detectors(lit))
		return ;
	if (detector(lit, result))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
		result_printer(result);
}