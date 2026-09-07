/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializatior.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:53:35 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/07 21:37:54 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializatior.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	*this = other;
	std::cout << "Serializer default copy constructor called." << std::endl;
}

Serializer &Serializer::operator=(const Serializer &value)
{
	(void)value;
	std::cout << "Serializer assigment operator called." << std::endl;

	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}


uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
