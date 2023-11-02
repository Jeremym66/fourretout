/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:59:51 by kaly              #+#    #+#             */
/*   Updated: 2023/11/02 18:05:04 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"
#include "Data.class.hpp"

int main()
{
	Data *  data = new Data;
	uintptr_t   raw;

	std::cout << data << std::endl;

	raw = Serializer::serialize(data);

	std::cout << raw << std::endl;

	data = Serializer::deserialize(raw);

	std::cout << data << std::endl;

	delete data;
	return 0;
}