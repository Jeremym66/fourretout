/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:56:30 by sdestann          #+#    #+#             */
/*   Updated: 2023/04/17 11:13:30 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_rev_int_tab(int *tab, size_t size)
{
	int	compteur;
	int	temp_value;

	compteur = 0;
	temp_value = 0;
	while (compteur < ((int)size / 2))
	{
		temp_value = tab[compteur];
		tab[compteur] = tab[(int)size - 1 - compteur];
		tab[(int)size - 1 - compteur] = temp_value;
		compteur++;
	}
}
