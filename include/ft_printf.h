/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:49:21 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/25 18:49:21 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_var_print {
	int	res;
	int	flagzero;
	int	precision;
	int	width;
	int	flagplus;
	int	flagminus;
	int	flaghash;
	int	flagspace;
} t_var_print;

int	ft_printf(const char *format, ...);


#endif
