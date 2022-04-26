/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:37:52 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/26 11:07:16 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//          ----------========== {   INCLUDES   } ==========----------

# include "../minilibx/mlx.h"
# include "../libft/include/libft.h"

//          ----------========== {     DEFS     } ==========----------

# define RES 32
# define E_CONT "La map n'a pas un contenu valide."
# define E_SQUARE "La map n'est pas rectangulaire."
# define E_CLOSE "La map n'est pas fermée."
# define E_ARGS "Les arguments sont incorrects."
# define E_BER "La map doit être en .ber."
# define E_FD "File descriptor non valide."

//          ----------========== {    STRUCT    } ==========----------

typedef struct s_img
{
	void	*ptr;
	int		sizex;
	int		sizey;
}			t_img;

typedef struct s_player
{
	int		x;
	int		y;
	size_t	moves;
	size_t	items;
}			t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_global
{
	int			fd;
	char		**map;
	int			sizex;
	int			sizey;
	t_img		img[5];
	t_player	player;
	t_vars		vars;
}				t_global;

//          ----------========== {     FCTS     } ==========----------

#endif