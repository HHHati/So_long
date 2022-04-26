/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:45:37 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/26 14:09:39 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


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

int	map_len(t_global *global)
{

}

void	map_join(t_global *global)
{
	
}

void	init_map(t_global *global, char **argv, int argc)
{
	char	**map;

	map = malloc(sizeof(char *));
	if (!map)
	{
		ft_printf("Error\n%s\n", E_ALLOC);
		exit(0);
	}
	map[0] = 0;
	check_args(argv, argc);
	global->fd = open(argv[1], O_RDONLY);
	if (global->fd < 0)
	{
		ft_printf("Error\n%s\n", E_FD);
		free(map);
		exit(0);
	}
	close(global->fd);
}
