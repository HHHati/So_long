/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:37:47 by bade-lee          #+#    #+#             */
/*   Updated: 2022/03/13 15:08:04 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*instance;
	void	*window;
	int		sizex;
	int		sizey;
	char	*title;

	sizex = 500;
	sizey = 400;
	title = "test";
	instance = mlx_init();
	window = mlx_new_window(instance, sizex, sizey, title);
}