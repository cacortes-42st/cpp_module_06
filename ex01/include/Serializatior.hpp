/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializatior.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:35:03 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/06 21:34:41 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATOR_HPP
#define SERIALIZATOR_HPP

struct	Data
{
	std::string	DataMember1;
	int	DataMember2;
};

class	 Serialize
{
	public:
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
	private:
		Serialize();
		Serialize(const Serialize &other);
		Serialize &operator=(const Serialize &value);
		~Serialize();		
};

#endif 