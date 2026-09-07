/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 21:35:25 by cacortes          #+#    #+#             */
/*   Updated: 2026/09/07 21:30:18 by cacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializatior.hpp"

int	main()
{
	std::cout << "\n===== DEFAULT TEST ====="<< std::endl;

	Data DataObject;
	uintptr_t example;
	Data *result;

	DataObject.DataMember1 = "Object1";

	example = Serializer::serialize(&DataObject);
	result = Serializer::deserialize(example);

	std::cout << "\nRunning comparison..\n" << std::endl;

	std::cout << "Old DataObject: " << &DataObject << std::endl;
	std::cout << "New DataObject: " << result << std::endl;
	
	if (&DataObject == result)
		std::cout << "\nThe two Data objects are equal."<< std::endl;
	else
		std::cout << "\nThe two Data objects aren't equal."<< std::endl;
	
	return (0);
}