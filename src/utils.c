/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:12:49 by Basile19          #+#    #+#             */
/*   Updated: 2022/05/16 16:22:43 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_player(t_global *global)
{
	int	x;
	int	y;

	y = 0;
	while (y < global->sizey)
	{
		x = 0;
		while (x < global->sizex)
		{
			if (global->map[y][x] == 'P')
			{
				global->player.x = x;
				global->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	null_init(t_global *global)
{
	size_t	i;

	i = 0;
	global->map = 0;
	global->vars.mlx = 0;
	global->vars.win = 0;
	while (i < 5)
	{
		global->img[i].ptr = 0;
		i++;
	}
}
