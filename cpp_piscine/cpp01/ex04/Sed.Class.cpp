/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.Class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:39:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/07 12:03:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.Class.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2)
{
    std::cout << "filename is : " << this->_filename << std::endl;
    std::cout << "s1 is : " << this->_s1 << std::endl;
    std::cout << "s2 is : " << this->_s2 << std::endl;
}

Sed::~Sed()
{
}

void    Sed::create_file()
{
    std::string outputFilename = _filename + ".replace";
    std::ofstream ofs(outputFilename);
    std::ifstream ifs(_filename);

    if(!ifs.is_open())
    {
        std::cout << "Error, couldn't open input file : " << this->_filename << std::endl;
        return ;
    }

    if(!ofs.is_open())
    {
        std::cout << "Error, couldn't open output file : " << this->_filename + ".replace" << std::endl;
        return ;
    }
    
    while (std::getline(ifs, this->_temp))
    {
        size_t start = this->_temp.find(this->_s1);
        while (start != -1)
        {
            std::string before = this->_temp.substr(0, start); // Partie avant la première occurrence de s1
            std::string after = this->_temp.substr(start + this->_s1.size()); // Partie après la première occurrence de s1
            this->_temp = before + this->_s2 + after; // Concaténation des parties avec s2 au milieu
            start = this->_temp.find(this->_s1);
        }
        ofs << this->_temp << std::endl;
    }
    ofs.close();
    ifs.close();
}