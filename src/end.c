/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:55:00 by bade-lee          #+#    #+#             */
/*   Updated: 2022/05/04 13:50:39 by Basile19         ###   ########.fr       */
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

void	end_msg(t_global *global)