/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:58:07 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/31 08:42:04 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.class.hpp"

Intern::Intern() 
{
    std::cout << "constructor Intern" << std::endl;
}

Intern::~Intern() 
{
    std::cout << "destructor Intern" << std::endl;
}

Intern::Intern(const Intern & src)
{
}

Intern & Intern::operator=(const Intern & rhs)
{
    return *this;
}

AForm *Intern::MakeForm(std::string nameform, std::string target)
{
    std::string form[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm *newform[3] = {new RobotomyRequestForm(target), new PresidentialPardonForm(target), new ShrubberyCreationForm(target)};
    int i = -1;
    int j = -1;

    while (++i < 3)
    {   
        if (form[i] == nameform)
        {
            std::cout << "Intern create " << nameform << std::endl;
            while (++j < 3)
            {
                if (j != i)
                    delete newform[j];
            }
            return (newform[i]); 
        }
    }
    while (++j < 3)
         delete newform[j];
    throw (NotAForm("Intern don't find this form!"));
    return NULL;
}

Intern::NotAForm::NotAForm(void)
{
    this->_msg = "We can't execute : The Form is not signed";
}

Intern::NotAForm::NotAForm(const char *msg) : _msg(msg)
{
}