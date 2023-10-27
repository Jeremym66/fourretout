/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:09:22 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/25 14:34:30 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

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
        void setGrade(int grade);

        void incrementGrade(void);
        void decrementGrade(void);
        

        class Exception : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return "Bureaucrat Exception";
                }
        };

        class GradeTooHighException : public Bureaucrat::Exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return "Grade too High : < 1";
                }
        };

        class GradeTooLowException : public Bureaucrat::Exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return "Grade too Low : > 150";
                }
        };

    private :

        int _Grade;
        std::string const _Name;
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i );