/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdestann <sdestann@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:06:20 by kaly              #+#    #+#             */
/*   Updated: 2023/08/09 14:51:40 by sdestann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/* la fonction free chars vide une string et le free*/

void	ft_free_chars(char *s)
{
	if (s)
	{
		s = NULL;
		free(s);
	}
}
