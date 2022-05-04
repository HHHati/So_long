/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:34:29 by Basile19          #+#    #+#             */
/*   Updated: 2022/05/04 13:56:41 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	key_up(t_global *global)
{
	if (global->map[global->player.y - 1][global->player.x] == '1')
		return ;
	else if (global->map[global->player.y - 1][global->player.x] == '0' ||
		global->map[global->player.y - 1][global->player.x] == 'C')
	{
		if (global->map[global->player.y - 1][global->player.x] == 'C')
			global->player.items -= 1;
		global->map[global->player.y - 1][global->player.x] = 'P';
		global->map[global->player.y][global->player.x] = '0';
		global->player.moves += 1;
		global->player.y -= 1;
		ft_printf("%i\n", global->player.moves);
	}
	else if (global->map[global->player.y - 1][global->player.x] == 'E')
		exit_game(global);
	map_reload(global);
}

void	key_down(t_global *global)
{
	if (global->map[global->player.y + 1][global->player.x] == '1')
		return ;
	else if (global->map[global->player.y + 1][global->player.x] == '0' ||
		global->map[global->player.y + 1][global->player.x] == 'C')
	{
		if (global->map[global->player.y + 1][global->player.x] == 'C')
			global->player.items -= 1;
		global->map[global->player.y + 1][global->player.x] = 'P';
		global->map[global->player.y][global->player.x] = '0';
		global->player.moves += 1;
		global->player.y += 1;
		ft_printf("%i\n", global->player.moves);
	}
	else if (global->map[global->player.y + 1][global->player.x] == 'E')
		exit_game(global);
	map_reload(global);
}

void	key_right(t_global *global)
{
	if (global->map[global->player.y][global->player.x + 1] == '1')
		return ;
	else if (global->map[global->player.y][global->player.x + 1] == '0' ||
		global->map[global->player.y][global->player.x + 1] == 'C')
	{
		if (global->map[global->player.y][global->player.x + 1] == 'C')
			global->player.items -= 1;
		global->map[global->player.y][global->player.x + 1] = 'P';
		global->map[global->player.y][global->player.x] = '0';
		global->player.moves += 1;
		global->player.x += 1;
		ft_printf("%i\n", global->player.moves);
	}
	else if (global->map[global->player.y][global->player.x + 1] == 'E')
		exit_game(global);
	map_reload(global);
}

void	key_left(t_global *global)
{
	if (global->map[global->player.y][global->player.x - 1] == '1')
		return ;
	else if (global->map[global->player.y][global->player.x - 1] == '0' ||
		global->map[global->player.y][global->player.x - 1] == 'C')
	{
		if (global->map[global->player.y][global->player.x - 1] == 'C')
			global->player.items -= 1;
		global->map[global->player.y][global->player.x - 1] = 'P';
		global->map[global->player.y][global->player.x] = '0';
		global->player.moves += 1;
		global->player.x -= 1;
		ft_printf("%i\n", global->player.moves);
	}
	else if (global->map[global->player.y][global->player.x - 1] == 'E')
		exit_game(global);
	map_reload(global);
}

void	key_exit(t_global *global)
{
	size_t	i;

	i = 0;
	if (global->map)
		free_map(global->map);
	while (i < IMG_NUMBER)
	{
		if (global->img[i].ptr)
			mlx_destroy_image(global->vars.mlx, global->img[i].ptr);
		i++;
	}
	if (global->vars.win)
		mlx_destroy_window (global->vars.mlx, global->vars.win);
	if (global->vars.mlx)
		free(global->vars.mlx);
	ft_printf("Fin du jeu !\n");
	exit(0);
	return (0);
}