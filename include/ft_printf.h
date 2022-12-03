/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:49:21 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/12/02 15:46:27 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define SPECIFIER "cspdiuxX%"

typedef struct s_var_print {
	int		isnumneg;
	int		flagzero;
	int		precision;
	int		flagdot;
	int		width;
	int		flagplus;
	int		flagminus;
	int		flaghash;
	int		flagspace;
	char	specifier;
}	t_var_print;

int		ft_printf(const char *format, ...);

int		print_c(t_var_print *var, unsigned char c);

int		print_per(t_var_print *var);

int		print_p(t_var_print *var, unsigned long long hex);

int		print_s(t_var_print *var, char *str);

int		print_u(t_var_print *var, unsigned int num);

int		print_d(t_var_print *var, int num);

int		print_x(t_var_print *var, unsigned int num);

char	*ft_left_pad_space(t_var_print *var, char *res);

char	*ft_right_pad_space(t_var_print *var, char *res);

char	*ft_left_pad_zero(t_var_print *var, char *res);

char	*ft_num_with_precision(t_var_print *var, char *res);

char	*ft_add_sign_space(char *res, char *sign);

char	*ft_itoa_hex(unsigned long long n);

int		ft_itoa_hex_len(unsigned long long n);

#endif
