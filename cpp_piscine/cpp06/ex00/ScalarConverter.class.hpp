/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:10:02 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/01 15:24:59 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <limits.h>
#include <float.h>
#include <cstdlib>

class ScalarConverter 
{
	public:
		static void	Convert(std::string param);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		
		ScalarConverter &	operator=(ScalarConverter const &rSym);

};
