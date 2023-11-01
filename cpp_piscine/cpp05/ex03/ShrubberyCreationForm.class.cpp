/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:27:39 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 09:21:19 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.class.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm::AForm("Tree", 145, 137, target)
{
    std::cout << "Shrubbery constructor target " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Shrubbery destructor target " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other) : AForm::AForm("Tree", 145, 137, other.getTarget())
{
    std::cout << "Shrubbery constructor copy target " << this->getTarget() << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    if (this != &rhs)
    {
        this->setTarget(rhs.getTarget());
    }
    return(*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getGradeToExecute() >= executor.getGrade() && this->getIsSigned() == true)
    {
        std::ofstream	file;

        std::cout << "Shrubbery executed by " << executor.getName() << std::endl;
	    std::string	name = this->getTarget() + "_shrubbery";
        std::cout << "Target : " << name << std::endl;
	    file.open(name.c_str(), std::ofstream::out);
        file << "                            " << std::endl;
        file << "              * *           " << std::endl;
        file << "           *    *  *        " << std::endl;
        file << "      *  *    *     *  *    " << std::endl;
        file << "     *     *    *  *    *   " << std::endl;
        file << " * *   *    *    *    *   * " << std::endl;
        file << " *     *  *    * * .#  *   *" << std::endl;
        file << " *   *     * #.  .# *   *   " << std::endl;
        file << "  *     '#.  #: #' * *    * " << std::endl;
        file << " *   * * '#. ##'       *    " << std::endl;
        file << "   *       '###             " << std::endl;
        file << "             '##            " << std::endl;
        file << "              ##.           " << std::endl;
        file << "              .##:          " << std::endl;
        file << "              :###          " << std::endl;
        file << "              ;###          " << std::endl;
        file << "            ,####.          " << std::endl;
        file << "############################" << std::endl;
        file.close();
    }
    else if (this->getIsSigned() == false)
        throw NotSignedException();
    else
        throw GradeTooLowException("Your grade is too low for execute this Tree's Form");
}