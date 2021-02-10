/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:36:38 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/05 18:33:54 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	parameters_length(const char *str, size_t *skip_len)
{
	size_t	i;

	i = 0;
	while (!ft_isalpha(str[i]) && str[i] != '%')
		i++;
	*skip_len = i + 2;
	return (i);
}

void	get_params(const char *str, size_t skip_len, va_list args,
		t_params *var_params)
{
	size_t	i;

	i = set_flags(str, var_params);
	i += set_width(str + i, var_params, args);
	set_precision((char *)str + i, var_params, args);
	var_params->type = str[skip_len];
}

size_t	print_variable(const char *str, size_t *skip_len, va_list args)
{
	size_t		printed_char_len;
	t_params	*var_params;

	printed_char_len = 0;
	var_params = ft_calloc(2, sizeof(t_params));
	get_params(str, parameters_length(str, skip_len), args, var_params);
	if (var_params->type == 'c')
		printed_char_len = print_c(args, var_params);
	else if (var_params->type == 'd' || var_params->type == 'i')
		printed_char_len = print_d(args, var_params);
	else if (var_params->type == 'p')
		printed_char_len = print_p(args, var_params);
	else if (var_params->type == '%')
		printed_char_len = print_pcnt(var_params);
	else if (var_params->type == 's')
		printed_char_len = print_s(args, var_params);
	else if (var_params->type == 'u')
		printed_char_len = print_u(args, var_params);
	else if (var_params->type == 'x')
		printed_char_len = print_x(args, var_params);
	else if (var_params->type == 'X')
		printed_char_len = print_x_upper(args, var_params);
	free((t_params *)var_params);
	return (printed_char_len);
}
