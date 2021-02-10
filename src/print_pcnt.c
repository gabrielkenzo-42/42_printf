/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkenzo-s <gkenzo-s@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:36:23 by gkenzo-s          #+#    #+#             */
/*   Updated: 2021/02/05 18:33:39 by gkenzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	print_pcnt(t_params *var_params)
{
	char	*str;
	size_t	size;

	str = ft_calloc(2, sizeof(char));
	*str = '%';
	size = print_in_screen(str, var_params);
	free(str);
	return (size);
}
