/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:35:20 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:37:05 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\r' || c == '\f');
}

int	string_is_only_space(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (!is_space(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*go_to_next_and_get_arg(char *line)
{
	int	i;

	i = 0;
	while (*line && (!is_space(*line)))
	{
		line++;
	}
	while (*line && (is_space(*line)))
	{
		line++;
	}
	while (line[i] && !is_space(line[i]) && line[i] != '\n')
	{
		i++;
	}
	return (ft_substr(line, 0, i));
}

int	is_numeric(char *str)
{
	if (!str || *str == '\0')
	{
		return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
