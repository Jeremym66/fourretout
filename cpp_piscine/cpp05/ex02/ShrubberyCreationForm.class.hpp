/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:27:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 08:47:34 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.class.hpp"

class ShrubberyCreationForm : public AForm
{
    private :

        ShrubberyCreationForm(void);

    public :

        ~ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm & other);

        ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
        virtual void execute(const Bureaucrat & executor) const;

};