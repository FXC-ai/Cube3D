/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:52:30 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 16:23:08 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putnbr_hex_fd(unsigned int n, char *base, int fd)
{
	char	display_n_char;

	display_n_char = 0;
	if (n > 0)
	{
		ft_putnbr_hex_fd((n / 16), base, fd);
		display_n_char = base[n % 16];
		ft_putchar_fd(display_n_char, fd);
	}
}

void	ft_print_hex(va_list args, char *base, int *ptr_c_count)
{
	unsigned int	hex_to_print;

	hex_to_print = va_arg(args, unsigned int);
	if (hex_to_print == 0)
	{
		ft_putchar_fd('0', 1);
		*ptr_c_count += 1;
	}
	else
	{
		ft_putnbr_hex_fd(hex_to_print, base, 1);
	}
	while (hex_to_print > 0)
	{
		hex_to_print = hex_to_print / 16;
		*ptr_c_count += 1;
	}
}
