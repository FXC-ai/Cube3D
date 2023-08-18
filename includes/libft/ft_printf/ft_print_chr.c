/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:49 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/07 15:59:00 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_chr(va_list args, int *ptr_c_count)
{
	char	char_to_print;

	char_to_print = va_arg(args, int);
	ft_putchar_fd(char_to_print, 1);
	*ptr_c_count += 1;
}
