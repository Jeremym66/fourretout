/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:01 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 13:42:41 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "AForm.class.hpp"

int main()
{
    ShrubberyCreationForm test("test");
    // ShrubberyCreationForm test2("test");
    Bureaucrat bob("Bob", 10);
    std::cout << std::endl <<"      Test 1 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm test2("test2");
        std::cout << test << test2 << bob;
        test2 = test;
        std::cout << test << test2 << bob;
        bob.signForm(test);
        test.execute(bob);
        bob.setGrade(150);
        test2.execute(bob);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl << "     Test 2 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        RobotomyCreationForm test3("Robot");
        std::cout << test3;

        bob.setGrade(10);
        test3.besigned(bob);
        std::cout << test3;

        test3.execute(bob);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    // std::cout << "-------------------------------------------" << std::endl;
    // std::cout << std::endl << "     Test 3 !!!!!!!" << std::endl;
    // std::cout << "-------------------------------------------" << std::endl;
    // try
    // {
    //     bob.setGrade(140);
    //     bob.signForm(test);
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << "-------------------------------------------" << std::endl;
    //     std::cout << std::endl << "     Test 4 !!!!!!!" << std::endl;
    // std::cout << "-------------------------------------------" << std::endl;
    // try
    // {
    //     bob.setGrade(10);
    //     bob.signForm(test);
    //     bob.signForm(test);
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << "-------------------------------------------" << std::endl;

    return 0;
}