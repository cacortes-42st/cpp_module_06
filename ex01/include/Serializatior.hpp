/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializatior.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:35:03 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/07 21:34:44 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATOR_HPP
#define SERIALIZATOR_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct	Data
{
	std::string	DataMember1;
	int	DataMember2;
};

class	 Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &value);
		~Serializer();		
};

#endif 