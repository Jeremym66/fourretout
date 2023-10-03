/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:07:55 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/01 09:00:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_CLASS_HPP__
# define __ZOMBIE_CLASS_HPP__

#include <iostream>
#include <string>

class Zombie {

public :

            Zombie(std::string name);
            ~Zombie(void);

            void    announce(void);


private :

            std::string _name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
