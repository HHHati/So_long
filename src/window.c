/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:43:06 by Basile19          #+#    #+#             */
/*   Updated: 2022/05/16 16:24:17 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_image(t_global *global)
{
	size_t		i;
	static char	*img[5] = {FLOOR, WALL, PLAYER, COLECTIBLE, EXIT};

	i = 0;
	while (i < 5)
	{
		global->img[i].ptr = mlx_xpm_file_to_image(global->vars.mlx, img[i],
				&global->img[i].sizex, &global->img[i].sizey);
		if (!global->img[i].ptr)
			error_img(global, E_IMG);
		i++;
	}
}

void	mlx_start(t_global *global)
{
	global->vars.mlx = mlx_init();
	global->vars.win = mlx_new_window(global->vars.mlx, global->sizex * RES,
			global->sizey * RES, "So_long");
	put_image(global);
	map_refresh(global);
	mlx_hook(global->vars.win, 17, 0, end_msg, global);
	mlx_key_hook(global->vars.win, so_long, global);
	mlx_loop(global->vars.mlx);
}
