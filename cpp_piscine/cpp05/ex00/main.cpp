/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:01 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/25 15:12:31 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

int main()
{
    Bureaucrat *bob2 = NULL;
    std::cout << "Test 1 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        Bureaucrat bob;
        bob2 = new Bureaucrat("bob2", 100);
        
        std::cout << bob << std::endl;
        std::cout << *bob2 << std::endl;

        bob.setGrade(100);

        std::cout << bob << std::endl;

        Bureaucrat Daryl("Daryl", 100);

        std::cout << Daryl << std::endl;

        bob = Daryl;

        std::cout << bob << std::endl;

        Bureaucrat test(Daryl);

        std::cout << test << std::endl;
        test.setGrade(1);

        test.decrementGrade();   
        test.incrementGrade();        
        test.incrementGrade();   
    }
    catch (Bureaucrat::Exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Test 2 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 10);

        std::cout << bob << std::endl;

    }
    catch (Bureaucrat::Exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Test 3!!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 1000);

        std::cout << bob << std::endl;

    }
    catch (Bureaucrat::Exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Test 4 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 150);

        std::cout << bob << std::endl;
        bob.decrementGrade();   

    }
    catch (Bureaucrat::Exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    if(bob2)
        delete bob2;

    return 0;
}