/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:15:55 by ocartier          #+#    #+#             */
/*   Updated: 2021/11/11 10:22:03 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		cur;
	char	*ret;

	cur = 0;
	ret = 0;
	while (s[cur])
	{
		if (s[cur] == (unsigned char)c)
			ret = (char *)(s + cur);
		cur++;
	}
	if (s[cur] == (unsigned char)c)
		ret = (char *)(s + cur);
	return (ret);
}
