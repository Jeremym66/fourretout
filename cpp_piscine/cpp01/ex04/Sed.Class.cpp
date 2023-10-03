/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.Class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:39:41 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/03 11:11:01 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.Class.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2), check(0)
{
    std::cout << "filename is : " << this->_filename << std::endl;
    std::cout << "s1 is : " << this->_s1 << std::endl;
    std::cout << "s2 is : " << this->_s2 << std::endl;
    int check = this->_s2.find(this->_s1);
    if (check != -1)
    {
        std::cout << "there is an iteration of \"" << this->_s1 << "\" in \"" << this->_s2 << "\"" << std::endl;
        std::cout << "Please restart the program, paying attention that s1 does not exist in s2" << std::endl;
        this->check = 1;
    }
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
        ifs.close();
        return ;
    }
    int i = 0;
    while (std::getline(ifs, this->_temp))
    {
        int start = this->_temp.find(this->_s1); // Calcule la taille jusqua literation de S1
        while (start != -1) // valeur de npos(-1) lorsque quil ny a plus d'iteration de s1 
        {
            std::string before = this->_temp.substr(0, start); // Partie avant la première occurrence de s1
            std::string after = this->_temp.substr(start + this->_s1.size()); // Partie après la première occurrence de s1
            this->_temp = before + this->_s2 + after; // Concaténation des parties avec s2 au milieu
            start = this->_temp.find(this->_s1);
            i++;
        }
        ofs << this->_temp << std::endl;
    }
    std::cout << "The string : \"" << this->_s1 << "\" was found " << i << " times" << std::endl; 
    ofs.close();
    ifs.close();
}