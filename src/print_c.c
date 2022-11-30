/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:00:27 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/30 12:14:01 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_var_print *var, unsigned char c)
{
	int	count;

	count = 0;
	if (var->flagminus)
	{
		count = write (1, &c, 1);
		while (var->width-- > 1)
			count += write (1, " ", 1);
	}
	else
	{
		while (var->width-- > 1)
			count += write (1, " ", 1);
		count += write (1, &c, 1);

	}
	return (count);
}


