/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:06:56 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/07 15:58:14 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putnbr_uint_fd(unsigned int n, int fd)
{
	unsigned int	display_n;
	int				display_n_char;

	display_n_char = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n >= 1)
	{
		display_n = n % 10;
		n = n / 10;
		if (n > 0)
			ft_putnbr_uint_fd(n, fd);
		display_n_char = display_n + 48;
		write(fd, &display_n_char, 1);
	}
}

void	ft_print_uint(va_list args, int *ptr_c_count)
{
	unsigned int	nbr_to_print;

	nbr_to_print = va_arg(args, unsigned int);
	ft_putnbr_uint_fd(nbr_to_print, 1);
	if (nbr_to_print == 0)
	{
		*ptr_c_count += 1;
	}
	while (nbr_to_print > 0)
	{
		nbr_to_print = nbr_to_print / 10;
		*ptr_c_count += 1;
	}	
}
