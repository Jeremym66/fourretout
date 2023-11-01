/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:27:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/31 07:32:34 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"
#include <random>

class RobotomyRequestForm : public AForm
{
    private :

        RobotomyRequestForm (void);

    public :

        ~RobotomyRequestForm (void);
        RobotomyRequestForm (const std::string target);
        RobotomyRequestForm (const RobotomyRequestForm & other);

        RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
        virtual void execute(const Bureaucrat & executor) const;

};