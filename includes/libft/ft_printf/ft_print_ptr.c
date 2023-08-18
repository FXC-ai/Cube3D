/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:25:37 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/07 15:57:57 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putnbr_ptr_fd(unsigned long n, int fd)
{
	unsigned long		display_n;
	char				display_n_char;
	char				*base;

	base = BASEHEX_MIN;
	display_n_char = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n >= 1)
	{
		display_n = n % 16;
		n = n / 16;
		if (n > 0)
			ft_putnbr_ptr_fd(n, fd);
		display_n_char = base[display_n];
		ft_putchar_fd(display_n_char, fd);
	}
}

void	ft_print_ptr(va_list args, int *ptr_c_count)
{
	unsigned long	ptr_to_print;

	ptr_to_print = va_arg(args, unsigned long);
	ft_putstr_fd("0x", 1);
	*ptr_c_count += 2;
	ft_putnbr_ptr_fd(ptr_to_print, 1);
	if (ptr_to_print == 0)
		*ptr_c_count += 1;
	while (ptr_to_print > 0)
	{
		ptr_to_print = ptr_to_print / 16;
		*ptr_c_count += 1;
	}
}
