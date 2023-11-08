/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/08 08:00:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Easyfind.hpp"

template<typename T>
int	easyfind(T const & array, int val) 
{
	typename T::const_iterator	it;
	typename T::const_iterator	ite = array.end();

	for (it = array.begin(); it != ite; ++it)
    {
        std::cout << *it << " checking...." << std::endl;
		if (*it == val)
			return *it;
	}
	throw Exception("No occurrence found !");
}
