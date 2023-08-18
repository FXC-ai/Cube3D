/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:54:38 by fcoindre          #+#    #+#             */
/*   Updated: 2022/10/27 14:30:44 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				r;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0')
		{
			r = (unsigned char) s1[i] - (unsigned char) s2[i];
			return (r);
		}
		if (s2[i] == '\0')
		{
			r = (unsigned char) s1[i] - (unsigned char) s2[i];
			return (r);
		}
		if (s1[i] != s2[i])
		{
			r = (unsigned char) s1[i] - (unsigned char) s2[i];
			return (r);
		}
		i++;
	}
	return (0);
}
