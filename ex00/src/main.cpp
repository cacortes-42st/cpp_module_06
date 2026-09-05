/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:52:11 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/05 15:12:41 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "The program needs only one argument to convert." << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}