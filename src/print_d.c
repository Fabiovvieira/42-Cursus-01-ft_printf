/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:43:19 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/01 22:50:15 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char	*ft_num_with_precision(t_var_print *var, char *res)
{
	char	*tmp;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(res);
	tmp = (char *)malloc(sizeof(char)* (var->precision + 1));
	while (i < (var->precision - size))
		*(tmp + i++) = '0';
	while (i < var->precision)
		*(tmp + i++) = *(res++);
	*(tmp + i) = *(res);
	return (tmp);
}

int	print_d(t_var_print *var, int num)
{
	char	*res;
	char	*tmp;

	res = ft_itoa(num);
	if (var->flagdot && var->precision > (int)ft_strlen(res))
	{
		tmp = ft_num_with_precision(var, res);
		free(res);
		res = tmp;
	}
	if (var->flagminus)
	{
		tmp = ft_right_pad_space(var, res);
		free (res);
		res = tmp;
	}
	else
	{
		if (!(var->flagdot) && var->flagzero)
		{
			tmp = ft_left_pad_zero(var, res);
			free (res);
			res = tmp;
		}
		else
		{
			tmp = ft_left_pad_space(var, res);
			free (res);
			res = tmp;
		}
	}
	write(1, res, ft_strlen(res));
	return (ft_strlen(res));
}
