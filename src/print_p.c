/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:51:03 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/30 17:50:27 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_itoa_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa_hex(unsigned long long n)
{
	int					len;
	unsigned long long	num;
	char				*nb;

	num = n;
	len = ft_itoa_hex_len(num);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (0);
	nb[len] = '\0';
	if (num == 0)
		nb[0] = '0';
	while (num > 0)
	{
		nb[len - 1] = "0123456789abcdef"[num % 10];
		num = num / 16;
		len --;
	}
	return (nb);
}


int	print_p(t_var_print *var, unsigned long long hex)
{
	int		count;
	char	*num;
	char	*res;

	(void)var;
	count = 0;
	num = ft_itoa_hex(hex);
	res = ft_strjoin("0x", num);
	printf("res =%s\n", res);
	return (count);
}
