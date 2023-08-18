/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:08:20 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/08 15:13:59 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;
	unsigned char	cc;

	i = 0;
	cs = (unsigned char *) s;
	cc = (unsigned char) c;
	while (i < n)
	{
		if (cs[i] == cc)
		{
			return ((void *) &s[i]);
		}
		i++;
	}
	return (NULL);
}
