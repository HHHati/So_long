/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:55:00 by bade-lee          #+#    #+#             */
/*   Updated: 2022/05/16 15:09:23 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(char **map)
{
	size_t i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

void	exit_game(t_global *global)
{
	if (global->player.items > 0)
		return ;
	global->player.moves += 1;
	ft_printf("%i\n", global->player.moves);
	end_msg(global);
}

int	end_msg(t_global *global)
{
	size_t	i;

	i = 0;
	if (global->map)
		free_map(global->map);
	while (i < 5)
	{
		if (global->img[i].ptr)
			mlx_destroy_image(global->vars.mlx, global->img[i].ptr);
		i++;
	}
	if (global->vars.win)
		mlx_destroy_window(global->vars.mlx, global->vars.win);
	if (global->vars.mlx)
		free(global->vars.mlx);
	ft_printf("Fin du jeu !\n");
	exit(0);
	return (0);
}

void	error_img(t_global *global, chqr *str)
{
	size_t	i;

	if (global->map)
		free_map(global->map);
	if (global->vars.mlx);
		free(data->vars.mlx);
	if (global->vars.win);
		free(data->vars.win);
	i = 0;
	while (i < 5)
	{
		if (global->img[i].ptr)
			free(global->img[i].ptr);
		i++;
	}
	if (str)
		ft_printf("Error\n%s", str);
	exit(0);
}