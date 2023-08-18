/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:38:20 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/07 15:58:49 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_print_format(const char c_format, va_list args, int *ptr_c_count)
{
	if (c_format == 'c')
		ft_print_chr(args, ptr_c_count);
	else if (c_format == 's')
		ft_print_str(args, ptr_c_count);
	else if (c_format == 'd' || c_format == 'i')
		ft_print_nbr(args, ptr_c_count);
	else if (c_format == 'p')
		ft_print_ptr(args, ptr_c_count);
	else if (c_format == '%')
		ft_print_prcent(ptr_c_count);
	else if (c_format == 'u')
		ft_print_uint(args, ptr_c_count);
	else if (c_format == 'x')
		ft_print_hex(args, BASEHEX_MIN, ptr_c_count);
	else if (c_format == 'X')
		ft_print_hex(args, BASEHEX_MAJ, ptr_c_count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		c_count;

	c_count = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_format(str[i + 1], args, &c_count);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			c_count++;
		}
		i++;
	}
	va_end(args);
	return (c_count);
}
