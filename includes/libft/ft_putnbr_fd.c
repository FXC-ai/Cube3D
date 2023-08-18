/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:57 by fcoindre          #+#    #+#             */
/*   Updated: 2022/11/08 14:13:30 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	display_n;
	int	display_n_char;

	display_n_char = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n == 0)
			write(fd, "0", 1);
		if (n < 0)
		{
			n = (n * -1);
			write(fd, "-", 1);
		}
		if (n >= 1)
		{
			display_n = n % 10;
			n = n / 10;
			if (n > 0)
				ft_putnbr_fd(n, fd);
			display_n_char = display_n + 48;
			write(fd, &display_n_char, 1);
		}	
	}
}
