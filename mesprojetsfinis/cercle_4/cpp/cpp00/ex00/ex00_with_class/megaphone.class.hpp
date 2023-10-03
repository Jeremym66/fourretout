/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:00:19 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 07:55:44 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_CLASS_H
# define MEGAPHONE_CLASS_H

# include <iostream>

class Megaphone {

public:
	char a;

	Megaphone(void);
	~Megaphone(void);

	void	up(char *str);

};

#endif