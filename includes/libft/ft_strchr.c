/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:09:10 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/07 18:38:49 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		caract;
	size_t		i;
	size_t		size_s;

	i = 0;
	caract = c;
	size_s = ft_strlen(s);
	while (i <= size_s)
	{
		if (s[i] == caract)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	return (NULL);
}
