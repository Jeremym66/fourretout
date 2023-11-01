/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:01 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/31 08:43:05 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "AForm.class.hpp"
#include "Intern.class.hpp"

int main()
{
    ShrubberyCreationForm test("test");
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
        RobotomyRequestForm test3("Robot");
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
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl << "     Test 3 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        PresidentialPardonForm test4("Nours");
        bob.setGrade(1);
        bob.signForm(test4);
        test4.execute(bob);
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
        Intern someRandomIntern;
        AForm*   rrf;

        rrf = someRandomIntern.MakeForm("robotomy request", "Bender");
        delete rrf;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl << "     Test 5 !!!!!!!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        Intern someRandomIntern;
        AForm*   rrf;

        rrf = someRandomIntern.MakeForm("Laser request", "Toto");
        delete rrf;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;

    return 0;
}