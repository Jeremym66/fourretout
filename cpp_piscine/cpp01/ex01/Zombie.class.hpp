/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 09:17:22 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_CLASS_HPP__
# define __ZOMBIE_CLASS_HPP__

#include <iostream>
#include <string>

class Zombie {

public :

            Zombie(void);
            ~Zombie(void);

            void    announce(void);
            void    setname(std::string, int i);

private :

            std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
