/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetezea <jmetezea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:14:14 by jmetezea          #+#    #+#             */
/*   Updated: 2023/09/08 09:50:35 by jmetezea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.Class.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage : " << av[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    int lvl;
    int i;

    lvl = 0;
    i = -1;
    while(av[1][++i])
        lvl += av[1][i];


    switch (lvl) // Supposons que vous utilisez la première lettre du niveau.
    {
        case 359: // correspond a DEBUG
        case 519: // correspond a debug
            harl.complain("DEBUG");
            // Pas de break ici pour afficher également les niveaux supérieurs.
        case 300: // correspond a INFO
        case 428: // correspond a info
            harl.complain("INFO");
            // Pas de break ici pour afficher également les niveaux supérieurs.
        case 534: // correspond a WARNING
        case 758: // correspond a warning
            harl.complain("WARNING");
            // Pas de break ici pour afficher également les niveaux supérieurs.
        case 394: // correspond a ERROR
        case 554: // correspond a error
            harl.complain("ERROR");
            break;
        default:
            std::cout << "Unknown level: " << av[1] << std::endl << std::endl;
            std::cout << "levels are <DEBUG> <INFO> <WARNING> <ERROR>" << std::endl << std::endl;
            break;
    }

    return 0;
}




