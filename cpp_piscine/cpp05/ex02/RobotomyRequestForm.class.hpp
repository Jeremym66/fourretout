/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:27:30 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/28 09:46:16 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"

class RobotomyCreationForm : public AForm
{
    private :

        RobotomyCreationForm (void);

    public :

        ~RobotomyCreationForm (void);
        RobotomyCreationForm (const std::string target);
        RobotomyCreationForm (const RobotomyCreationForm & other);

        RobotomyCreationForm &	operator=(RobotomyCreationForm const & rhs);
        virtual void execute(const Bureaucrat & executor) const;

};