/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:39:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/07 12:01:54 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SED_CLASS_HPP__
# define __SED_CLASS_HPP__

#include <iostream>
#include <fstream>

class Sed
{

private:

    // std::ofstream   _ofs;
    // std::ifstream   _ifs;
    
    std::string _filename;
    std::string _s1;
    std::string _s2;

    std::string _temp;

public:

    Sed(std::string filename, std::string s1, std::string s2);
    ~Sed();
    
    void    create_file();


};

#endif