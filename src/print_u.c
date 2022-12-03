/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:13:28 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 10:57:43 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(t_var_print *var, unsigned int num)
{
	char	*res;
	char	*tmp;
	int		count;

	count = 0;
	res = ft_itoa((long)num);
	if (var->flagdot && (var->precision > (int)ft_strlen(res) || res[0] == '0'))
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
	count = write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
