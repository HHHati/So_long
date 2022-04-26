/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:45:37 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/26 11:33:19 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	init_map(t_global *global, char **argv, int argc)
{
	check_args(argv, argc);
	global->fd = open(argv[1], O_RDONLY);
	if (global->fd < 0)
	{
		ft_printf("Error\n%s\n", E_FD);
		exit(0);
	}
	close(global->fd);
}

void	check_args(char **argv, int argc)
{
	size_t	i;

	if (argc != 2 || ft_strlen(argv[1]) < 5)
	{
		ft_printf("Error\n%s\n", E_ARGS);
		exit(0);
	}
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e'
		|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
	{
		ft_printf("Error\n%s\n", E_BER);
		exit(0);
	}
}
