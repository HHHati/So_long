/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:45:37 by bade-lee          #+#    #+#             */
/*   Updated: 2022/05/16 15:41:57 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_error(char **map, int fd)
{
	if (map)
		free_map(map);
	if (fd > -1)
		close (fd);
	ft_printf("Error\n%s\n", E_MAP);
}

char **map_join(char **map, char *line, int fd)
{
	char	**updated_map;
	size_t	i;

	i = 0;
	if (!line)
		return(map);
	while (map[i])
		i++;
	updated_map = malloc((i + 2) * sizeof(char *));
	if (!updated_map)
		map_error(map, fd);
	i = 0;
	while (map[i])
	{
		updated_map[i] = map[i];
		i++;
	}
	updated_map[i] = line;
	updated_map[i + 1] = 0;
	free(map);
	return(updated_map);
}

char **map_reader(int fd)
{
	char	**map;
	size_t	i;

	map = malloc(2 * sizeof(char *));
	if (!map)
		map_error(0, fd);
	map[0] = get_next_line(fd);
	if (!map[0])
		map_error(map, fd);
	map[1] = 0;
	i = 1;
	while (map[i - 1])
	{
		map = map_join(map, get_next_line(fd), fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = 0;
	return (map);
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
	global->map = map_reader(global->fd);
	if (!global->map || !global->map[0] || !global->map[1] || !global->map[2]
		|| !global->map[0][0] || !global->map[0][1] || !global->map[0][2])
		error_reason(global, E_LITTLE);
	check_square(global);
	check_close(global);
	check_characters(global);
	set_player(global);
	close(global->fd);
}
