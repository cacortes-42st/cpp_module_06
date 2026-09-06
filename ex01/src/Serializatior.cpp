/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializatior.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:53:35 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/06 21:01:45 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializatior.hpp"

Serialize::Serialize()
{
	std::cout << "Serialize default constructor called." << std::endl;
}

Serialize::Serialize(const Serialize &other)
{
	*this = other;
	std::cout << "Serialize default copy constructor called." << std::endl;
}

Serialize &Serialize::operator=(const Serialize &value)
{
	(void)value;
	std::cout << "Serialize assigment operator called." << std::endl;

	return *this;
}

Serialize::~Serialize()
{
	std::cout << "Serialize destructor called" << std::endl;
}


uintptr_t serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}