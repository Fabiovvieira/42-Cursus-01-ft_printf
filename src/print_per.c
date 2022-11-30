/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:25:22 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/30 16:21:44 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_per(t_var_print *var)
{
	if (!(var->flagminus) && !(var->flagdot)
	 && !(var->flaghash) && !(var->flagplus)
	 && !(var->flagspace) && !(var->flagzero))
		return(write(1, "%", 1));
	return (0);
}
