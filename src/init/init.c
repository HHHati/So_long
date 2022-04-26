/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:45:37 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/26 11:09:33 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_global *global, char **argv, int argc)
{
	check_args(argv, argc);
	global->fd = open(argv[1], O_RDONLY);
	if (global->fd < 0)
	{
		ft_printf("Error\n%s\n", E_FD)
		exit(0);
	}
	close(global->fd);
}

void	check_args(char **argv, int argc)
{
	size_t	i;

	if (argc != 2 || ft_strlen(argv[1] < 5))
	{
		ft_printf("Error\n%s\n", E_ARGS)
		exit(0);
	}
	i = ft_strlen(argv[1]);
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
	{
		ft_printf("Error\n%s\n", E_BER)
		exit(0);
	}
}
