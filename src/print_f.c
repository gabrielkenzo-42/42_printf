/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:50:21 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/13 22:50:22 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_f(va_list args, t_params *var_params, size_t *printed_len)
{
	double	n;
	char	*str;

	n = va_arg(args, double);
	if (var_params->has_precision++ == 0)
		var_params->precision_value = 6;
	str = ft_ftoa(n, var_params->precision_value);
	*printed_len += print_in_screen(str, var_params);
	free(str);
}
