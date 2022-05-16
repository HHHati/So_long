/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:41:11 by Basile19          #+#    #+#             */
/*   Updated: 2022/05/16 15:43:02 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_img(t_global *global, char c, int x, int y)
{
	int			i;
	static char str[6] = "01PCE";

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	mlx_put_image_to_window(global->vars.mlx, global->vars.win,
		global->img[n].ptr, x * RES, y * RES);
}

void	map_refresh(t_global *global)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < global->sizey)
	{
		x = 0;
		while (x < global->sizex)
		{
			set_img(global, global->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	so_long(int keycode, t_global *global)
{
	if (keycode == 53)
		key_exit(global);
	else if (keycode == 13)
		key_up(global);
	else if (keycode == 1)
		key_down(global);
	else if (keycode == 0)
		key_left(global);
	else if (keycode == 2)
		key_right(global);
	return (0);
}