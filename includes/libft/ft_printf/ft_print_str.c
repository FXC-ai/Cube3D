/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:59:08 by fcoindre          #+#    #+#             */
/*   Updated: 2023/02/07 15:58:06 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_str(va_list args, int *ptr_c_count)
{
	char	*str_to_print;

	str_to_print = va_arg(args, char *);
	if (str_to_print == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*ptr_c_count += 6;
	}	
	else
	{
		ft_putstr_fd(str_to_print, 1);
		*ptr_c_count += ft_strlen(str_to_print);
	}
}
