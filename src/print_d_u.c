/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:35:27 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/04 14:33:19 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_u(va_list args, t_params *var_params)
{
	char	*str;
	size_t	i;

	str = ft_utoa(va_arg(args, unsigned int));
	if (*str == '0' && !var_params->precision_value &&\
		var_params->has_precision)
		*str = '\0';
	i = print_in_screen(str, var_params);
	free(str);
	return (i);
}

size_t	print_d(va_list args, t_params *var_params)
{
	char	*str;
	size_t	i;

	str = ft_itoa(va_arg(args, int));
	if (*str == '0' && !var_params->precision_value &&\
		var_params->has_precision)
		*str = '\0';
	i = print_in_screen(str, var_params);
	free(str);
	return (i);
}
