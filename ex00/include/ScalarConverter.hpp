/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 11:49:17 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/09 10:23:21 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cctype>

struct	resultPrint
{
	bool	MaxMinI;
	bool	MaxMinC;
	bool	NoPrint;

	char	chr;
	int		in;
	float	flt;
	double	dbl;
};

class	ScalarConverter
{	
	public: 
		static void convert(std::string lit);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &value);
		~ScalarConverter();
};

#endif