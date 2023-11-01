/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:51:53 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/31 08:19:14 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

class Intern
{
    public :

        Intern(void);
        ~Intern(void);
        Intern(const Intern & src);
        Intern & operator=(const Intern & rhs);

        AForm *MakeForm(std::string nameform, std::string target);

        class NotAForm : public std::exception
        {
            private :

                const char  *_msg;

            public :

                NotAForm(void);
                NotAForm(const char *_msg);            
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };
};