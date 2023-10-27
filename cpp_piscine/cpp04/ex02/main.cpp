/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:29:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 13:41:19 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "cat.class.hpp"
#include "dog.class.hpp"
#include "wronganimal.class.hpp"
#include "wrongcat.class.hpp"

int main()
{

    const AAnimal *i = new Cat();
    i->makeSound();


    // pour tester quon ne puisses pas instancier un AAnimal il faut decommenter
    // les 2 lignes si dessous et compiler a nouveau une erreur de compilation 
    // devrait apparaitre expliquant quon ne puisses pas instancier une classe abstraite


    // const AAnimal *j = new AAnimal();
    // j->makeSound();

    delete  i;
    
    return (0);
}
