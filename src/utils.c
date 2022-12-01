/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:04:29 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/01 10:48:43 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_left_pad_space(t_var_print *var, char *res)
{
	int		size;
	char	*tmp;
	int		i;

	i = 0;
	size = ft_strlen(res);
	tmp = ft_strdup(res);
	if (var->width > size)
	{
		tmp = (char *)malloc(sizeof(char)* (var->width + 1));
		while (i < (var->width - size))
			*(tmp + i++) = ' ';
		while (i < var->width)
			*(tmp + i++) = *(res++);
		*(tmp + i) = *(res);
	}
	return (tmp);
}

char	*ft_right_pad_space(t_var_print *var, char *res)
{
	int		size;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(res);
	tmp = ft_strdup(res);
	if (var->width > size)
	{
		tmp = (char *)malloc(sizeof(char)* (var->width + 1));
		while (i < size)
			*(tmp + i++) = *(res++);
		while (j++ < (var->width - size))
			*(tmp + i++) = ' ';
		*(tmp + i) = '\0';
	}
	return (tmp);
}


char	*ft_left_pad_zero(t_var_print *var, char *res)
{
	int		size;
	char	*tmp;
	int		i;

	i = 0;
	size = ft_strlen(res);
	tmp = ft_strdup(res);
	if (var->width > size)
	{
		tmp = (char *)malloc(sizeof(char)* (var->width + 1));
		while (i < (var->width - size))
			*(tmp + i++) = ' ';
		while (i < var->width)
			*(tmp + i++) = *(res++);
		*(tmp + i) = *(res);
	}
	return (tmp);
}
