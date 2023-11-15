/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:41:48 by jmetezea          #+#    #+#             */
/*   Updated: 2023/11/15 11:23:30 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

int main()
{
    // AMateria * materia_1 = new AMateria();
    const Ice * materia_1 = new Ice();
    const Ice * materia_3 = new Ice();
    const AMateria * materia_2 = new AMateria("fire");
    std::cout << "Materia1's Type is \"" << materia_1->getType() << "\"" << std::endl;
    std::cout << "Materia2's Type is \"" << materia_2->getType() << "\"" << std::endl;
    delete (materia_1);
    delete (materia_2);
    delete (materia_3);
    return 0;
}