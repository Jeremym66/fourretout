/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:33:36 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 13:55:40 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"

RobotomyCreationForm::RobotomyCreationForm(const std::string target) : AForm::AForm("Robotisation", 72, 45, target)
{
    std::cout << "Robotomy constructor target " << this->getTarget() << std::endl;
}

RobotomyCreationForm::~RobotomyCreationForm(void)
{
    std::cout << "Robotomy destructor target " << this->getTarget() << std::endl;
}

RobotomyCreationForm::RobotomyCreationForm(const RobotomyCreationForm & other) : AForm::AForm("Robotisation", 72, 45, other.getTarget())
{
    std::cout << "Robotomy constructor copy target " << this->getTarget() << std::endl;
}

RobotomyCreationForm & RobotomyCreationForm::operator=(RobotomyCreationForm const & rhs)
{
    if (this != &rhs)
    {
        this->setTarget(rhs.getTarget());
    }
    return(*this);
}

void RobotomyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getGradeToExecute() >= executor.getGrade() && this->getIsSigned() == true)
    {
        std::cout << "Vvvvvvvvvvvvvrrrrrrrrrrrrrrr(drilling noises)" << std::endl;
        if (rand() % 2)
            std::cout << "Vvvvvvvrrrrrr   " << this->getTarget() << " has been robotomized" << std::endl;
        else
            std::cout << "Vvvvvvvrrrrrr  .... The robotomy failed his mission " << this->getTarget() << " is alive !!!" << std::endl;

    }
    else if (this->getIsSigned() == false)
        throw NotSignedException();
    else
        throw GradeTooLowException("Your grade is too low for execute this Robotisation's Form");
}