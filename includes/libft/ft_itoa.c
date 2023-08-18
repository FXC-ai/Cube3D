/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:00:13 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/07 15:07:11 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size_nb(int nb, int is_negativ)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		size++;
	}
	if (is_negativ == -1)
	{
		size = size + 1;
	}
	return (size);
}

static char	*imintoa(void)
{
	char	*tab;

	tab = malloc(sizeof(char) * (12));
	if (tab == NULL)
		return (NULL);
	tab[0] = '-';
	tab[1] = '2';
	tab[2] = '1';
	tab[3] = '4';
	tab[4] = '7';
	tab[5] = '4';
	tab[6] = '8';
	tab[7] = '3';
	tab[8] = '6';
	tab[9] = '4';
	tab[10] = '8';
	tab[11] = '\0';
	return (tab);
}

static void	itoa_result(int is_negativ, int nb, int size, char *tab)
{
	tab[size] = '\0';
	while (--size >= 1)
	{
		tab[size] = (nb % 10) + 48;
		nb = nb / 10;
	}	
	if (is_negativ == -1)
		tab[0] = '-';
	else
		tab[0] = nb + 48;
}

char	*ft_itoa(int nb)
{
	char	*tab;
	int		is_negativ;
	int		size;

	is_negativ = 1;
	if (nb == -2147483648)
		return (imintoa());
	if (nb < 0)
	{
		nb = -nb;
		is_negativ = -1;
	}
	size = find_size_nb(nb, is_negativ);
	tab = malloc (sizeof(char) * (size + 1));
	if (tab == NULL)
		return (NULL);
	itoa_result(is_negativ, nb, size, tab);
	return (tab);
}
