/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:25:14 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 09:20:55 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"

AForm::AForm(void) : _Name("NoName"), _GradeToExecute(150), _GradeToSign(150), _issigned(false)
{
    std::cout << "constructor Form" << std::endl;
}

AForm::AForm(std::string name, int gradetosign, int gradetoexe, std::string target) : _Name(name), _GradeToExecute(gradetoexe), _GradeToSign(gradetosign), _Target(target)
{
    if (gradetosign > 150 || gradetoexe > 150)
        throw AForm::GradeTooLowException();
    else if (gradetosign < 1 || gradetoexe < 1)
        throw AForm::GradeTooHighException();
    
    this->_issigned = false;
    std::cout << "constructor Form name : " << name << " grade to sign : " << gradetosign << " ; to execute : " << gradetoexe << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "destructor Form " << this->_Name << std::endl;
}

AForm::AForm(AForm const & a) : _Name(a.getName()), _GradeToExecute(a.getGradeToSign()), _Target(a.getTarget())
{
    std::cout << "constructor Form copy" << std::endl;
    *this = a;
}

AForm & AForm::operator=(AForm const & rhs)
{
    if (this != &rhs)
    {
        this->_GradeToSign = rhs.getGradeToSign();
        this->_GradeToExecute = rhs.getGradeToExecute();
        this->_issigned = rhs.getIsSigned();
    }
    return(*this);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_GradeToExecute);
}

int AForm::getGradeToSign(void) const
{
    return (this->_GradeToSign);
}

bool AForm::getIsSigned(void) const
{
    return (this->_issigned);
}

std::string AForm::getName(void) const
{
    return (this->_Name);
}

std::string AForm::getTarget(void) const
{
    return this->_Target;
}

void AForm::setTarget(std::string target)
{
    _Target = target;
}

void AForm::setGradeToSign(int grade)
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

void AForm::setGradeToExecute(int grade)
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

void AForm::besigned(Bureaucrat & bu)
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
            throw GradeTooLowException(" because the Form is already signed");
        }
        else
        {
            std::cout << bu.getName() << " couldn't sign " << this->_Name;
            throw GradeTooLowException(" because his grade is too low for sign this Form");
        }
    }
}

std::ostream & operator<<( std::ostream & o, AForm const & i )
{
	o << i.getName() << ", Form grade to sign : " << i.getGradeToSign() << std::endl;
	o << i.getName() << ", Form grade to execute : " << i.getGradeToExecute() << std::endl;
	if (i.getIsSigned() == true)
        o << i.getName() << ", Form's status : Signed !" << std::endl;
    else
        o << i.getName() << ", Form's status : Not Signed !" << std::endl;
    o << i.getName() << ", Form's Target : " << i.getTarget() << std::endl;
	return o;
}

AForm::GradeTooHighException::GradeTooHighException(void)
{
    this->_msg = "Grade too High : grade max 1 grade min 150";
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{
}

AForm::GradeTooLowException::GradeTooLowException(void)
{
    this->_msg = "Grade too Low : grade max 1 grade min 150";
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{
}

AForm::NotSignedException::NotSignedException(void)
{
    this->_msg = "We can't execute : The Form is not signed";
}

AForm::NotSignedException::NotSignedException(const char *msg) : _msg(msg)
{
}