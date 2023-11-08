/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:43:18 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/08 14:51:44 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public:

		typedef	typename std::stack<T>::container_type::iterator iterator;
		
        iterator	begin()
        {
             return this->c.begin(); 
        }
		
        iterator	end()
        {
            return this->c.end();
        }
};