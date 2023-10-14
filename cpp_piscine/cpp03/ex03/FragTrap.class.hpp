/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:56:58 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 15:57:18 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.class.hpp"

class FragTrap : public ClapTrap 
{
public :

    FragTrap(std::string name);
    ~FragTrap(void);
    FragTrap(FragTrap const & a);
    FragTrap & operator=(FragTrap const & rhs);

    void    highFivesGuys(void);
    void    attack(const std::string & target);

private :

};