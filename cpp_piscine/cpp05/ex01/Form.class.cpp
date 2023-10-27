/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:14:59 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/27 11:46:33 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"

Form::Form(void) : _Name("NoName"), _GradeToExecute(150), _GradeToSign(150), _issigned(false)
{
    std::cout << "constructor Form" << std::endl;
}

Form::Form(std::string name, int gradetosign, int gradetoexe) : _Name(name), _GradeToExecute(gradetoexe), _GradeToSign(gradetosign)
{
    if (gradetosign > 150 || gradetoexe > 150)
        throw Form::GradeTooLowException();
    else if (gradetosign < 1 || gradetoexe < 1)
        throw Form::GradeTooHighException();
    
    this->_issigned = false;
    std::cout << "constructor Form name : " << name << " grade to sign : " << gradetosign << " ; to execute : " << gradetoexe << std::endl;
}

Form::~Form(void)
{
    std::cout << "destructor Form " << this->_Name << std::endl;
}

Form::Form(Form const & a) : _Name(a.getName()), _GradeToExecute(a.getGradeToSign())
{
    std::cout << "constructor Form copy" << std::endl;
    *this = a;
}

Form & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
    {
        this->_GradeToSign = rhs.getGradeToSign();
        this->_GradeToExecute = rhs.getGradeToExecute();
        this->_issigned = rhs.getIsSigned();
    }
    return(*this);
}

int Form::getGradeToExecute(void) const
{
    return (this->_GradeToExecute);
}

int Form::getGradeToSign(void) const
{
    return (this->_GradeToSign);
}

bool Form::getIsSigned(void) const
{
    return (this->_issigned);
}

std::string Form::getName(void) const
{
    return (this->_Name);
}

void Form::setGradeToSign(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _GradeToSign = grade;
    std::cout << "Form name : " << this->_Name << " >>> grade to sign : " << grade << std::endl;
    return;
}

void Form::setGradeToExecute(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        _GradeToExecute = grade;
    std::cout << "Form name : " << this->_Name << " >>>> grade to execute : " << grade << std::endl;
    return;
}

void Form::besigned(Bureaucrat & bu)
{
    if (bu.getGrade() <= this->_GradeToSign && this->_issigned == false)
    {
        this->_issigned = true;
        std::cout << bu.getName() << " signed " << this->_Name << std::endl; 
    }
    else
    {
        if (this->_issigned == true)
        {
            std::cout << bu.getName() << " couldn't sign " << this->_Name;
            throw GradeTooLowException(" because the form is already signed");
        }
        else
        {
            std::cout << bu.getName() << " couldn't sign " << this->_Name;
            throw GradeTooLowException(" because his grade is too low for sign this form");
        }
    }
}

std::ostream & operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", Form grade to sign : " << i.getGradeToSign() << std::endl;
	o << i.getName() << ", Form grade to execute : " << i.getGradeToExecute() << std::endl;
	if (i.getIsSigned() == true)
        o << i.getName() << ", Form's status : Signed !" << std::endl;
    else
        o << i.getName() << ", Form's status : Not Signed !" << std::endl;
	return o;
}

Form::GradeTooHighException::GradeTooHighException(void)
{
    this->_msg = "Grade too High : grade max 1 grade min 150";
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{
}

Form::GradeTooLowException::GradeTooLowException(void)
{
    this->_msg = "Grade too Low : grade max 1 grade min 150";
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{
}