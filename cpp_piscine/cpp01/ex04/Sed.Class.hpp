/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:39:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 11:05:37 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>

class Sed
{

public:

    int check;

    Sed(std::string filename, std::string s1, std::string s2);
    ~Sed();
    
    void    create_file();

private:
    
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string _temp;
   
};
