/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:10:03 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/27 11:44:42 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(void) : _Name("NoName"), _Grade(150)
{
    std::cout << "constructor Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _Grade = grade;
    std::cout << "constructor Bureaucrat name : " << name << " grade : " << grade << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "destructor Bureaucrat " << this->_Name << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & a) : _Name(a.getName())
{
    std::cout << "constructor Bureaucrat copy" << std::endl;
    *this = a;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    if (this != &rhs)
        this->_Grade = rhs.getGrade();
    return(*this);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_Grade);
}

std::string Bureaucrat::getName(void) const
{
    return (this->_Name);
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _Grade = grade;
    std::cout << "Bureaucrat name : " << this->_Name << " grade : " << grade << std::endl;
    return;
}

void    Bureaucrat::incrementGrade(void)
{
    if (this->_Grade - 1 <= 0)
        throw GradeTooHighException();
    else
        _Grade--;
    std::cout << "Bureaucrat name : " << this->_Name << " grade : " << _Grade << std::endl;
    return;
}   

void    Bureaucrat::decrementGrade(void)
{
    if (this->_Grade + 1 >= 150)
        throw GradeTooLowException();
    else
        _Grade++;
    std::cout << "Bureaucrat name : " << this->_Name << " grade : " << _Grade << std::endl;
    return;
}

void    Bureaucrat::signForm(Form & form)
{
    form.besigned(*this); 
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)
{
    this->_msg = "Grade too High : grade max 1 grade min 150";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)
{
    this->_msg = "Grade too Low : grade max 1 grade min 150";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{
}
