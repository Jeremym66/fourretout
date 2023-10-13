/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:10:48 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/13 18:20:13 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main()
{
    ClapTrap Robot1("Fer");
    ClapTrap Robot2("Bois");
    ClapTrap Robot3("Papier");

    Robot1.getAll();
    Robot2.getAll();
    Robot3.getAll();

    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.takeDamage(10);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.beRepaired(20);
    Robot1.getAll();
    Robot1.Setattackdmg(10);
    Robot2.Setattackdmg(5);

    Robot1.attack("Papier");
    Robot2.attack("Papier");
    Robot3.takeDamage(Robot2.Getattackdmg());
    Robot2.attack("Papier");
    Robot3.takeDamage(Robot2.Getattackdmg());
    Robot1.getAll();
    Robot3.getAll();

    Robot3.beRepaired(20);
    Robot3.attack("Bois");
    Robot3.takeDamage(Robot2.Getattackdmg());

    return (0);
}