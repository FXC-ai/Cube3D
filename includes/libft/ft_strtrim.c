/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:26:04 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/08 11:33:43 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char caract, const char *charset);
static int	is_char(char const *s1, char const *set);
char		*ft_strtrim(char const *s1, char const *set);

static int	is_in_set(char caract, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == caract)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	is_char(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (is_in_set(s1[i], set) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr_end;
	char	*ptr_start;
	size_t	result_size;
	char	*result;

	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	if (is_char(s1, set) == 0)
		return (ft_strdup(""));
	result_size = ft_strlen(s1);
	ptr_end = ((char *) s1) + ft_strlen(s1);
	ptr_start = (char *) s1;
	while (ptr_end-- > s1 && is_in_set(*ptr_end, set))
		result_size --;
	while (ptr_start < ptr_end && is_in_set(*ptr_start, set))
	{
		ptr_start ++;
		result_size --;
	}
	result = (char *) malloc((sizeof(char) * result_size) + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, ptr_start, (result_size + 1));
	return (result);
}
