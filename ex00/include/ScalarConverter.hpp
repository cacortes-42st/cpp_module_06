/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 11:49:17 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/03 20:50:32 by cacortes         ###   ########.fr       */
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
	bool	psd;

	char	chr;
	int		in;
	float	flt;
	double	dbl;
};

class	ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &value);
		~ScalarConverter();
		
		static void convert(std::string lit, resultPrint result);
};

#endif