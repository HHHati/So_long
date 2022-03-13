/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_param_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:20 by bade-lee          #+#    #+#             */
/*   Updated: 2021/12/02 10:42:38 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_d(int *counter, va_list params)
{
	const int	i = va_arg(params, int);
	char		*temp;

	temp = ft_itoa(i);
	ft_putnbr_fd(i, 1);
	*counter = *counter + ft_strlen(temp);
	free(temp);
	return (1);
}
