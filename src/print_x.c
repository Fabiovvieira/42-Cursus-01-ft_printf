/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:19:13 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 17:28:42 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_str_toupper(char **s)
{
	char	*str;

	str = *s;
	if (!str)
		return ;
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	print_x(t_var_print *var, unsigned int num)
{
	char	*res;
	char	*tmp;
	int		count;

	count = 0;
	res = ft_itoa_hex((unsigned long long)num);
	if (var->flagdot && var->precision > (int)ft_strlen(res))
	{
		tmp = ft_num_with_precision(var, res);
		free(res);
		res = tmp;
	}
	if (var->flagzero && !(var->flagdot) && !(var->flagminus))
	{
		tmp = ft_left_pad_zero(var, res);
		free (res);
		res = tmp;
	}
	if (var->flaghash && res[0] != '0')
	{
		tmp = ft_add_sign_space(res, "0x");
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
		tmp = ft_left_pad_space(var, res);
		free (res);
		res = tmp;
	}
	if (var->specifier == 'X')
		ft_str_toupper(&res);
	count = write(1, res, ft_strlen(res));
	free(res);
	return (count);
}
