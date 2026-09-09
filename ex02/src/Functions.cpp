/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:21:08 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/09 11:31:03 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"

Base * generate(void)
{
	std::srand(std::time(NULL));
	int indx = std::rand() % 3;

	if (indx == 0)
		return new ClassA();
	else if (indx == 1)
		return new ClassB();
	else
		return new ClassC();
}

void identify(Base* p)
{
	if (dynamic_cast<ClassA *>(p))
		std::cout << "Type of object: A" << std::endl;
	else if (dynamic_cast<ClassB *>(p))
		std::cout << "Type of object: B" << std::endl;
	else if (dynamic_cast<ClassC *>(p))
		std::cout << "Type of object: C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		ClassA& a = dynamic_cast<ClassA&>(p);
		(void)a;
		std::cout << "Type of object: A" << std::endl;
		return;
	}
	catch (std::exception & error)
	{
	}

	try
	{
		ClassB& b = dynamic_cast<ClassB&>(p);
		(void)b;
		std::cout << "Type of object: B" << std::endl;
		return;
	}
	catch (std::exception & error)
	{
	}


	try
	{
		ClassC& c = dynamic_cast<ClassC&>(p);
		(void)c;
		std::cout << "Type of object: C" << std::endl;
		return;
	}
	catch (std::exception & error)
	{
	}
}