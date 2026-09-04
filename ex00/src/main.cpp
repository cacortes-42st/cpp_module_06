/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:52:11 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/04 11:01:44 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	initStruct(resultPrint &result)
{
	(void)result;
	result.psd = false;
	result.chr = '\0';
	result.in = 0;
	result.flt = 0;
	result.dbl = 0;
}

int	main(int argc, char **argv)
{
	resultPrint	result;

	if (argc != 2)
	{
		std::cout << "The program needs only one argument to convert." << std::endl;
		return 1;
	}

	initStruct(result);
	ScalarConverter::convert(argv[1], result);

	return (0);
}