/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:21:24 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 09:21:03 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
{

   private :

        int _GradeToSign;
        int _GradeToExecute;
        bool    _issigned;
        std::string const _Name;
        std::string _Target;


    public :

        AForm(void);
        virtual ~AForm(void);
        AForm(std::string name, int gradetosign, int gradetoexe, std::string target);
        AForm(AForm const & a);
        AForm & operator=(AForm const & rhs);

        std::string getName(void) const;
        std::string getTarget(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
        bool getIsSigned(void) const;

        void setTarget(std::string target);
        void setGradeToSign(int grade);
        void setGradeToExecute(int grade);
        void besigned(Bureaucrat & bu);
        virtual void execute(const Bureaucrat & executor) const = 0;

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
        
        class NotSignedException : public std::exception
        {
            private :

                const char  *_msg;
            
            public :

                NotSignedException(void);
                NotSignedException(const char *_msg);
                const char* what() const throw()
                {
                    return this->_msg;
                }
        };

 
};

std::ostream & operator<<( std::ostream & o, AForm const & i );


