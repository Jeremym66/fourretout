/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <kaly@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:58:53 by kaly              #+#    #+#             */
/*   Updated: 2023/11/02 18:15:15 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Data
{
	public:
		Data();
		Data(Data const &src);
		~Data();

		Data &	operator=(Data const &rSym);
		int		getnbr() const;
	private:
		int	_nbr;
};

std::ostream &	operator<<(std::ostream & o, Data const &rSym);