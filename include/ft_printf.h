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

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"


# define SPECIFIER "cspdiuxX%"

typedef struct s_var_print {
	int		res;
	int		flagzero;
	int		precision;
	int		flagdot;
	int		width;
	int		flagplus;
	int		flagminus;
	int		flaghash;
	int		flagspace;
	char	specifier;
} t_var_print;

int	ft_printf(const char *format, ...);

int	print_c(t_var_print *var, unsigned char c);

int	print_per(t_var_print *var);

int	print_p(t_var_print *var, unsigned long long hex);

#endif
