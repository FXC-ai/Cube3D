/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:58:13 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 15:58:15 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	check_if_is_wall(char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && is_space(line[2]))
	{
		return (1);
	}
	else if (line[0] == 'S' && line[1] == 'O' && is_space(line[2]))
	{
		return (1);
	}
	else if (line[0] == 'W' && line[1] == 'E' && is_space(line[2]))
	{
		return (1);
	}
	else if (line[0] == 'E' && line[1] == 'A' && is_space(line[2]))
	{
		return (1);
	}
	return (0);
}

static int	check_for_1_or_0(char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
	{
		i++;
	}
	if (line[i] == '1' || line[i] == '0')
	{
		return (1);
	}
	return (0);
}

static int	parse_line(char *line)
{
	if (check_if_is_wall(line))
	{
		return (1);
	}
	else if (line[0] == 'F' && is_space(line[1]))
	{
		return (1);
	}
	else if (line[0] == 'C' && is_space(line[1]))
	{
		return (1);
	}
	else if (line[0] != 'F' && line[0] != 'C'
		&& check_if_is_wall(line) == 0 && string_is_only_space(line) == 0)
	{
		return (-1);
	}
	else if (check_for_1_or_0(line))
	{
		return (-1);
	}
	else
		return (0);
	return (1);
}

int	parser(char **copy)
{
	int	i;
	int	found;
	int	end;

	i = 0;
	found = 0;
	while (copy[i])
	{
		if (parse_line(copy[i]) == 1)
		{
			found ++;
			end = i;
		}
		else if (parse_line(copy[i]) == -1 && found != 6)
		{
			printf("Error : You didn't init all as it should be before map.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (end);
}
