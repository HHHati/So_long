/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_param_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:23 by bade-lee          #+#    #+#             */
/*   Updated: 2021/12/02 10:42:36 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_i(int *counter, va_list params)
{
	const int	i = va_arg(params, int);
	char		*temp;

	temp = ft_itoa(i);
	ft_putnbr_fd(i, 1);
	*counter = *counter + ft_strlen(temp);
	free(temp);
	return (1);
}
