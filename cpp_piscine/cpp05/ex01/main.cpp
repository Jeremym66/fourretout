/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:01 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/27 11:46:52 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main()
{
    Form test("Formulaire A", 100, 120);
    Bureaucrat bob("Bob", 10);
    std::cout << std::endl <<"      Test 1 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        Form test2;
        std::cout << test << bob;
        std::cout << test2;

        test2 = test;
        
        std::cout << test2;
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
        Form test3(test);
        std::cout << test3;

        test3.setGradeToSign(50);
        test3.setGradeToExecute(80);
        std::cout << test3;

        bob.setGrade(50);
        test3.besigned(bob);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl << "     Test 3 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        bob.setGrade(140);
        bob.signForm(test);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
        std::cout << std::endl << "     Test 4 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        bob.setGrade(10);
        bob.signForm(test);
        bob.signForm(test);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}