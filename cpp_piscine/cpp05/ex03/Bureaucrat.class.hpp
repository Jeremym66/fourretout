/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:09:22 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 07:42:48 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.class.hpp"

class AForm;

class Bureaucrat
{
    public :

        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const & a);
        Bureaucrat & operator=(Bureaucrat const & rhs);

        std::string getName(void) const;
        int getGrade(void) const;
        void    setGrade(int grade);

        void    incrementGrade(void);
        void    decrementGrade(void);
        void    signForm(AForm & form);
        
        class GradeTooHighException : public std::exception
        {
            private :

                const char  *_msg;
            
            public :

                GradeTooHighException(void);
                GradeTooHighException(const char *_msg);
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };

        class GradeTooLowException : public std::exception
        {
           private :

                const char  *_msg;
            
            public :

                GradeTooLowException(void);
                GradeTooLowException(const char *_msg);
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };

    private :

        int _Grade;
        std::string const _Name;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i );