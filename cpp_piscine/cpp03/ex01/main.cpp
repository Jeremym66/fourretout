/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:10:48 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/14 15:22:49 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main()
{
    ClapTrap Robot1("Grincheux");
    ScavTrap Robot2("Timide");
    ScavTrap Robot3(Robot2);

    Robot3.Setname("Fofolle");
    Robot1.getAll();
    Robot2.getAll();

    Robot2.guardGate();
    Robot2.ScavTrap::attack("Fer");
    Robot2.ClapTrap::attack("Fer");

    return (0);
}