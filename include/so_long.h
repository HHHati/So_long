/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:37:52 by bade-lee          #+#    #+#             */
/*   Updated: 2022/05/16 16:52:50 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//          ----------========== {   INCLUDES   } ==========----------

# include "../minilibx/mlx.h"
# include "../libft/include/libft.h"
# include <fcntl.h>

//          ----------========== {     DEFS     } ==========----------

# define RES 32

# define FLOOR "sprites/Floor.xpm"
# define WALL "sprites/Wall.xpm"
# define PLAYER "sprites/Player.xpm"
# define COLECTIBLE "sprites/Colectible.xpm"
# define EXIT "sprites/Exit.xpm"

# define E_CONT "La map n'a pas un contenu valide."
# define E_SQUARE "La map n'est pas rectangulaire."
# define E_CLOSE "La map n'est pas fermée."
# define E_ARGS "Les arguments sont incorrects."
# define E_BER "La map doit être en .ber."
# define E_FD "File descriptor non valide."
# define E_ALLOC "Problème d'allocation."
# define E_MAP "Problème de lecture de la map."
# define E_IMG "Problème de lecture de l'image."
# define E_LITTLE "La map est trop petite."

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

int		main(int argc, char **argv);
void	init_map(t_global *global, char **argv, int argc);
void	check_args(char **argv, int argc);
void	check_characters(t_global *global);
void	check_close(t_global *global);
void	check_square(t_global *global);
void	error_reason(t_global *global, char *str);
void	map_error(char **map, int fd);
char 	**map_join(char **map, char *line, int fd);
char	**map_reader(int fd);
void	free_map(char **map);
void	mlx_start(t_global *global);
void	put_image(t_global *global);
int		end_msg(t_global *global);
void	null_init(t_global *global);
void	error_img(t_global *global, char *str);
int		so_long(int keycode, t_global *global);
void	set_player(t_global *global);
void	exit_game(t_global *global);
void	map_refresh(t_global *global);
void	key_up(t_global *global);
void	key_down(t_global *global);
void	key_right(t_global *global);
void	key_left(t_global *global);
void	key_exit(t_global *global);

#endif