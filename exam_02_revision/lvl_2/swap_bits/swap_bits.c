/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaly <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:36:27 by kaly              #+#    #+#             */
/*   Updated: 2023/06/08 17:13:29 by kaly             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char	bit;

	while (i--)
	{
		bit = (octet >> i & 1);
		ft_putchar(bit + 48);
	}
	ft_putchar('\n');
}*/

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/*int	main(int ac, char **av)
{
	unsigned char	c = 65;
	
	print_bits(65);
	c = swap_bits(c);
	print_bits(c);
}*/
/*
Cette fonction swap_bits prend un octet (unsigned char) en entrée et effectue un échange des 4 bits de poids faible avec les 4 bits de poids fort. Voici une explication détaillée de la fonction :

octet >> 4: Cette opération de décalage à droite de 4 bits déplace les 4 bits de poids fort de l'octet vers la droite, en les remplaçant par des zéros. Les 4 bits de poids faible sont perdus lors de ce décalage.

Par exemple, si octet a la valeur binaire 11011011, après le décalage à droite de 4 bits, il deviendra 00001101. Les bits qui étaient à l'origine de poids faible sont maintenant tous à zéro.

octet << 4: Cette opération de décalage à gauche de 4 bits déplace les 4 bits de poids faible de l'octet vers la gauche, en les remplaçant par des zéros. Les 4 bits de poids fort sont perdus lors de ce décalage.

Reprenons l'exemple précédent. Après le décalage à gauche de 4 bits, octet deviendra 10110000. Les bits qui étaient à l'origine de poids fort sont maintenant tous à zéro.

| (OU logique) : Cette opération combine les résultats des décalages à droite et à gauche en effectuant un OU logique bit à bit entre les deux valeurs. Cela signifie que si un bit est à 1 dans l'un ou l'autre des résultats, il sera à 1 dans le résultat final.

En utilisant notre exemple, le résultat du OU logique entre 00001101 et 10110000 sera 10111101.

Le résultat de l'opération OU logique est renvoyé en tant que résultat de la fonction swap_bits.

En résumé, la fonction swap_bits échange les 4 bits de poids faible avec les 4 bits de poids fort de l'octet donné. Elle utilise les opérations de décalage à droite et à gauche ainsi que le OU logique pour effectuer cet échange.*/
