/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:08:52 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/08 15:17:26 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*cs1;
	char	*cs2;
	size_t	i;
	int		result;

	cs1 = (char *) s1;
	cs2 = (char *) s2;
	i = 0;
	result = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
		{
			result = (unsigned char) cs1[i] - (unsigned char) cs2[i];
			return (result);
		}
		i++;
	}
	return (result);
}
