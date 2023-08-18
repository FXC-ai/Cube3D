/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:04:38 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/08 15:26:10 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
			a = (char *) &haystack[i];
		c = 0;
		while (needle[c] == haystack[i + c] && (i + c) < len)
		{
			if (needle[c + 1] == '\0')
				return (a);
			c++;
		}
		i++;
	}
	return (NULL);
}
