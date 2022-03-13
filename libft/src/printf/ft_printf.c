/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:43:59 by bade-lee          #+#    #+#             */
/*   Updated: 2021/12/01 14:36:00 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_param(int param, va_list params, size_t *counter)
{
	static int	(*function[9])() = {&param_c, &param_s,
		&param_p, &param_d, &param_i, &param_u,
		&param_xlow, &param_xup, &param_prc};

	function[param](counter, params);
}

int	ft_printf(const char *param, ...)
{
	static char	*options = "cspdiuxX%";
	size_t		i;
	size_t		counter;
	va_list		list;

	i = 0;
	counter = 0;
	va_start(list, param);
	while (param[i])
	{
		if (param[i] == '%' && ft_strchr(options, param[i + 1]))
		{
			ft_apply_param(ft_strchr(options, param[i + 1]) - options,
				list, &counter);
			i++;
		}
		else
		{
			write(1, &param[i], 1);
			counter++;
		}
		i++;
	}
	va_end(list);
	return (counter);
}
