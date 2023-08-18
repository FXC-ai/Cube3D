/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:11:35 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/08 15:22:37 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len_to_cpy;

	len_to_cpy = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize > (srclen + 1))
		len_to_cpy = srclen;
	else
		len_to_cpy = dstsize - 1;
	while (len_to_cpy > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len_to_cpy--;
	}
	*dst = '\0';
	return (srclen);
}
