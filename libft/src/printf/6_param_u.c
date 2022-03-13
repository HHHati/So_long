/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_param_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:26 by bade-lee          #+#    #+#             */
/*   Updated: 2021/12/02 10:48:03 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_u(int *counter, va_list params)
{
	char	*temp;

	temp = ft_itoa(va_arg(params, unsigned int));
	ft_putstr_fd(temp, 1);
	*counter = *counter + ft_strlen(temp);
	free(temp);
	return (1);
}
