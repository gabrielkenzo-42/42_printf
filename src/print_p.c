/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:36:18 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/08 15:16:00 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p(va_list args, t_params *var_params, size_t *printed_len)
{
	long long	n;
	char		*str;
	char		*temp_str;
	int			len;

	n = va_arg(args, long long);
	str = ft_int_to_hex(n);
	if (var_params->has_precision && var_params->precision_value == 0 && n == 0)
		*str = 0;
	len = ft_strlen(str);
	if (var_params->precision_value > len && !var_params->has_minus)
	{
		temp_str = ft_calloc(var_params->precision_value - len, sizeof(char));
		ft_memset(temp_str, '0', var_params->precision_value - len);
		str = ft_strjoin(temp_str, str);
	}
	temp_str = ft_strjoin("0x", str);
	*printed_len += print_in_screen(temp_str, var_params);
	free(str);
	free(temp_str);
}
