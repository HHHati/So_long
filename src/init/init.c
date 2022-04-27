/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:45:37 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/27 13:26:20 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	map_error(char **map1, char **map2, int fd)
{
	if (map1)
		free_map(map1);
	if (map2)
		free_map(map2);
	if (fd > -1)
		close (fd);
	ft_printf("Error\n%s\n", E_MAP)
	
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

void	init_map(t_global *global, char **argv, int argc)
{
	check_args(argv, argc);
	global->fd = open(argv[1], O_RDONLY);
	if (global->fd < 0)
	{
		ft_printf("Error\n%s\n", E_FD);
		exit(0);
	}
	global->map = map_reader(global->fd)
	if (!data->map || !global->map[0] || !global->map[1] || !global->map[2]
		|| !global->map[0][0] || !global->map[0][1] || !global->map[0][2])
		error_reason(global, E_LITTLE);
	check_characters(global);
	check_close(global);
	check_square(global);
	//set_player(global)
	close(global->fd);
}
