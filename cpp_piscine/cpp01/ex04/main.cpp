/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 07:38:46 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/07 08:13:18 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.Class.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return (EXIT_FAILURE);

    Sed test(av[1], av[2], av[3]);

    test.create_file();
    
    return (EXIT_SUCCESS);
}