/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:29:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/20 15:58:53 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "cat.class.hpp"
#include "dog.class.hpp"
#include "wronganimal.class.hpp"
#include "wrongcat.class.hpp"
#include "brain.class.hpp"

int main()
{
    int i = -1;
    const Animal* meta[5];

    while(++i < 5)
        meta[i] = new Cat();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    i = -1;
    while(++i < 5)
        meta[i]->makeSound();

    // i->getBrain()->getIdeas();

    i = -1;
    while(++i < 5)
        delete (meta[i]);
    // delete (i);
    // delete (j);
    // return (0);


    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // i->getBrain()->getIdeas();

    // delete (meta);
    // delete (i);
    // delete (j);
    // return (0);
}

git@github.com:ntu213/42.git