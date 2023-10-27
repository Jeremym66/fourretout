/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:15:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/27 11:15:36 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form
{

   private :

        int _GradeToSign;
        int _GradeToExecute;
        bool    _issigned;
        std::string const _Name;

    public :

        Form(void);
        ~Form(void);
        Form(std::string name, int gradetosign, int gradetoexe);
        Form(Form const & a);
        Form & operator=(Form const & rhs);

        std::string getName(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool getIsSigned(void) const;

        void setGradeToSign(int grade);
        void setGradeToExecute(int grade);
        void besigned(Bureaucrat & bu);

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

 
};

std::ostream & operator<<( std::ostream & o, Form const & i );