/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 11:18:28 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/08 14:33:49 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

int	main()
{
	Base *inst;
	inst = generate();

	std::cout << "\n===== OBJECT FIRST IMPRESSION TEST ====="<< std::endl;
	identify(inst);

	std::cout << "\n===== OBJECT SECOND IMPRESSION TEST ====="<< std::endl;
	identify(*inst);
	
	std::cout << "\n===== END ====="<< std::endl;
	delete inst;

	return (0);
}