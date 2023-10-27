/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:29:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 10:47:17 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "cat.class.hpp"
#include "dog.class.hpp"
#include "wronganimal.class.hpp"
#include "wrongcat.class.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    // const WrongAnimal* wrongmeta = new WrongAnimal();
    // const WrongAnimal* wrongi = new WrongCat();

    // std::cout << wrongi->getType() << " " << std::endl;
    // wrongi->makeSound();
    // wrongmeta->makeSound();

    delete (meta);
    delete (i);
    delete (j);
    // delete (wrongmeta);
    // delete (wrongi);
    return (0);
}