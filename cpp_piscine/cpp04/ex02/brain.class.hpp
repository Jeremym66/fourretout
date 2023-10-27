/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:41:38 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 11:57:35 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
// #include "cat.class.hpp"
// #include "dog.class.hpp"


class Brain
{
    public :

        Brain(void);
        ~Brain(void);
        Brain(Brain const & a);
        Brain & operator=(Brain const & rhs);
        
        void    generateIdeas(void);

        std::string ideas[100];
};