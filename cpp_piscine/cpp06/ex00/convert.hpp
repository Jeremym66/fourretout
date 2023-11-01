/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:59:02 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/01 12:52:32 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>

bool isInt(std::string &str);
bool isChar(std::string &str);
bool isFloat(std::string &str);
bool isDouble(std::string &str);
bool doubleIsParticular(std::string &str);
bool floatIsParticular(std::string &str);
int isOthers(std::string &str);
