/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:43:19 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 17:48:55 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(t_var_print *var, int num)
{
	char	*res;
	char	*tmp;
	int		count;

	count = 0;
	if (num < 0)
	{
		res = ft_itoa(((long)num) * -1);
		var->isnumneg = 1;
	}
	else
		res = ft_itoa((long)num);
	if (var->flagdot && var->precision > (int)ft_strlen(res))
	{
		tmp = ft_num_with_precision(var, res);
		free(res);
		res = tmp;
	}
	else if (var->flagzero && !(var->flagdot) && !(var->flagminus))
	{
		tmp = ft_left_pad_zero(var, res);
		free (res);
		res = tmp;
	}
	if (num < 0)
	{
		tmp = ft_add_sign_space(res, "-");
		res = tmp;
	}
	if (var->flagplus)
	{
		if (num >= 0)
		{
			tmp = ft_add_sign_space(res, "+");
			res = tmp;
		}
	}
	else if (var->flagspace)
	{
		if (num >= 0)
		{
			tmp = ft_add_sign_space(res, " ");
			res = tmp;
		}
	}
	if (var->flagminus)
	{
		tmp = ft_right_pad_space(var, res);
		free (res);
		res = tmp;
	}
	else
	{
		tmp = ft_left_pad_space(var, res);
		free (res);
		res = tmp;
	}
	count = write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
