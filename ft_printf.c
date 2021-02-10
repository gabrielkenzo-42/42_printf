/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:44:33 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/03 16:10:37 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	fit_norm(char *temp, size_t printed_char_len, va_list args)
{
	size_t	i;
	size_t	*skip_len;

	i = 0;
	skip_len = ft_calloc(2, sizeof(size_t));
	while (temp[i])
	{
		if (temp[i] == '%')
		{
			printed_char_len += print_variable(temp + i + 1, skip_len, args);
			i += *skip_len;
		}
		else
		{
			ft_putchar(temp[i++]);
			printed_char_len++;
		}
	}
	free(skip_len);
	return (printed_char_len);
}

size_t			ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	printed_char_len;
	char	*temp;

	va_start(args, str);
	printed_char_len = 0;
	temp = ft_strdup(str);
	printed_char_len = fit_norm(temp, printed_char_len, args);
	va_end(args);
	free(temp);
	return (printed_char_len);
}
