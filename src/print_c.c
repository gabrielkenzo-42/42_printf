/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:35:17 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/03 15:44:17 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(va_list args, t_params *var_params, size_t *printed_len)
{
	char	str;
	char	*new_str;

	str = va_arg(args, int);
	new_str = ft_calloc(2, sizeof(char));
	new_str[0] = str;
	if (new_str[0] == 0)
	{
		var_params->width_value--;
		*printed_len += print_in_screen(new_str, var_params) + 1;
		free(new_str);
	}
	else
	{
		*printed_len += print_in_screen(new_str, var_params);
		free(new_str);
	}
}
