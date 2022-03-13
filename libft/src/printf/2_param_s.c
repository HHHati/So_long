/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_param_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:15 by bade-lee          #+#    #+#             */
/*   Updated: 2021/12/02 10:35:40 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_s(int *counter, va_list params)
{
	const char	*str = va_arg(params, char *);

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*counter = *counter + 6;
		return (1);
	}
	ft_putstr_fd((char *)str, 1);
	*counter = *counter + ft_strlen(str);
	return (1);
}
