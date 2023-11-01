/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:26:15 by jmetezea          #+#    #+#             */
/*   Updated: 2023/10/31 07:32:37 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.class.hpp"

class PresidentialPardonForm : public AForm
{
    private :

        PresidentialPardonForm (void);

    public :

        ~PresidentialPardonForm (void);
        PresidentialPardonForm (const std::string target);
        PresidentialPardonForm (const PresidentialPardonForm & other);

        PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
        virtual void execute(const Bureaucrat & executor) const;

};