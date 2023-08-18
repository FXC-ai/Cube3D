/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 08:57:21 by fcoindre          #+#    #+#             */
/*   Updated: 2022/10/30 09:00:35 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	while (i < count * size)
	{
		*(result + i) = 0;
		i++;
	}
	return ((void *) result);
}
