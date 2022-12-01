/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:47:56 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/01 18:05:51 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char	*ft_str_with_precision(t_var_print *var, char *res)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char)* (var->precision + 1));
	while (i < var->precision)
		*(tmp + i++) = *(res++);
	*(tmp + i) = '\0';
	return (tmp);
}

int	print_s(t_var_print *var, char *str)
{
	char	*res;
	char	*tmp;

	res = ft_strdup(str);
	if (var->flagdot && var->precision < (int)ft_strlen(str))
		res = ft_str_with_precision(var, str);
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
	write(1, res, ft_strlen(res));
	return (ft_strlen(str));
}
