/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:22:16 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/04 13:42:01 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>
void	swap(T & a, T & b);

template<typename T>
const T	& min(T & a, T & b);

template<typename T>
const T	& max(T & a, T & b);
