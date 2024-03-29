/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:25:08 by bade-lee          #+#    #+#             */
/*   Updated: 2022/05/16 16:21:03 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_reason(t_global *global, char *str)
{
	free_map(global->map);
	ft_printf("Error\n%s\n", str);
	exit (0);
}

void	check_square(t_global *global)
{
	int	x;

	x = 0;
	global->sizex = 0;
	global->sizey = 0;
	while (global->map[0][global->sizex] &&
			global->map[0][global->sizex] != '\n')
		global->sizex += 1;
	while (global->map[global->sizey])
	{
		x = 0;
		while (global->map[global->sizey][x] &&
				global->map[global->sizey][x] != '\n')
			x++;
		if (x != global->sizex)
			error_reason(global, E_SQUARE);
		global->sizey += 1;
	}
}

void	check_close(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->sizex)
	{
		if (global->map[0][i] != '1' ||
			global->map[global->sizey - 1][i] != '1')
			error_reason(global, E_CLOSE);
		i++;
	}
	i = 0;
	while (i < global->sizey)
	{
		if (global->map[i][0] != '1' ||
			global->map[i][global->sizex - 1] != '1')
			error_reason(global, E_CLOSE);
		i++;
	}
}

static int	check_content(char i, int *c, int *e, int *p)
{
	if (i == 'C')
		*c += 1;
	else if (i == 'E')
		*e += 1;
	else if (i == 'P')
		*p += 1;
	else if (i == '0' || i == '1')
		return (1);
	else
		return (0);
	return (1);
}

void	check_characters(t_global *global)
{
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;

	c = 0;
	p = 0;
	e = 0;
	y = 0;
	while (y < global->sizey)
	{
		x = 0;
		while (x < global->sizex)
		{
			if (!check_content(global->map[y][x], &c, &e, &p))
				error_reason(global, E_CONT);
			x++;
		}
		y++;
	}
	global->player.items = c;
	if (p != 1 || e < 1 || c < 1)
		error_reason(global, E_CONT);
}
