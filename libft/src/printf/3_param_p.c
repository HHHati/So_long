/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_param_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:17 by bade-lee          #+#    #+#             */
/*   Updated: 2021/12/02 10:22:16 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char *str)
{
	int	n;
	int	i;

	n = 1;
	i = ft_strlen(str);
	if (i == 0 || i == 1)
	{
		return (0);
	}
	while (n != i)
	{
		if (str[n] == '+' || str[n] == '-' || str[n] == str[n + 1])
		{
			return (0);
		}
		n++;
	}
	return (1);
}

static void	ft_putnbr_base(unsigned long long int nbr, char *base, int *counter)
{
	unsigned long long int	n;
	unsigned long long int	i;

	if (ft_check(base) == 1)
	{
		i = ft_strlen(base);
		if (nbr < 0)
		{
			n = -nbr;
			ft_putchar_fd('-', 1);
			*counter = *counter + 1;
		}
		else
		{
			n = nbr;
		}
		if (n > i - 1)
		{
			ft_putnbr_base(n / i, base, counter);
			n %= i;
		}
		ft_putchar_fd(base[n], 1);
		*counter = *counter + 1;
	}
}

int	param_p(int *counter, va_list params)
{
	const unsigned long long int	nb = va_arg(params, unsigned long long int);

	ft_putstr_fd("0x", 1);
	*counter = *counter + 2;
	ft_putnbr_base(nb, "0123456789abcdef", counter);
	return (1);
}
