/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.Class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:13:09 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/07 14:11:25 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_CLASS_HPP__
# define __HARL_CLASS_HPP__

#include <iostream>
#include <string>
#include <functional>

class Harl
{

public:

    Harl();
    ~Harl();

    void complain(std::string level);

private:

    void            (Harl::*_Function)(void);
    std::string	    _level_mess[4];
	void            (Harl::*_ptr_fonction[4])(void);

    void debug(void); 
    void info(void);
    void warning(void);
    void error(void);

};

#endif