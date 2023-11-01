/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:24:29 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/31 07:33:35 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm::AForm("Robotisation", 25, 5, target)
{
    std::cout << "Robotomy constructor target " << this->getTarget() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Robotomy destructor target " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) : AForm::AForm("Robotisation", 25, 5, other.getTarget())
{
    std::cout << "Robotomy constructor copy target " << this->getTarget() << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    if (this != &rhs)
    {
        this->setTarget(rhs.getTarget());
    }
    return(*this);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	if (this->getGradeToExecute() >= executor.getGrade() && this->getIsSigned() == true)
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else if (this->getIsSigned() == false)
        throw NotSignedException();
    else
        throw GradeTooLowException("Your grade is too low for execute this Robotisation's Form");
}