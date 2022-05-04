/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:41:11 by Basile19          #+#    #+#             */
/*   Updated: 2022/05/04 13:57:48 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long(t_global *global)
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