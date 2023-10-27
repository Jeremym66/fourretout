/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:29:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/24 12:11:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.class.hpp"
#include "cat.class.hpp"
#include "dog.class.hpp"
#include "wronganimal.class.hpp"
#include "wrongcat.class.hpp"

int main()
{
    int i = 0;
    const Animal* meta[10];

    while (i < 5)
        meta[i++] = new Cat();
    while (i < 10)
        meta[i++] = new Dog();
    i = 0;
    while (i < 10)
        meta[i++]->makeSound();
    i = 0;
    while (i < 10)
        delete (meta[i++]);
    
    return (0);
}
