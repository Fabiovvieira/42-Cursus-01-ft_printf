/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:02:48 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/03 10:41:37 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	a;
	int	b;
	// int *d;
	// int c = 12;
	// d = &c;

	a = ft_printf("|%d|\n", INT_MIN);
	b = printf("|%d|\n", INT_MIN);
	printf("%d\n",a);
	printf("%d\n",b);
	return(0);
}
