/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:37:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/19 22:40:55 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define P "imgs/mario_3.png"
# define W "imgs/wall_1.png"
# define E "imgs/mario_3.png"
# define C "imgs/coin_1.png"
# define EN "imgs/flower_1.png"
# define G "imgs/flower_1.png"
# define IMG_SIZE 48

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_mapdata
{
	char	**map;
	t_point	size;
	t_point	point;
	int		player;
	int		exit;
	int		collect;
}				t_mapdata;

typedef struct s_img
{
	void			*wall;  
	void			*player;
	void			*exit;  
	void			*ground; 
	void			*coin;
	t_point			size;  
}	t_img;

typedef struct s_game
{
	void			*mlx;		// pointer to the mlx
	void			*window;	// pointer to the window
	t_point			wndw_size;	// window size

	int				og_collect;	// original collectable to be able to reset
	int				collect;	// current value, reducing one each time you pick up one
	int				moves;		// moves counter, adding one each time you spend a turn
	t_img			img;
}	t_game;

typedef enum e_components
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'M',
	FOLLOWER = 'F'
}	t_components;

/*--------------Map Read-------------------*/

int			count_lines_map(char *file);
int			count_column_map(t_mapdata mapdata);
char		**allocate_memory_to_map(char *file);
char		**read_map(char *file);
t_mapdata	map(char *file);

/*--------------Checker Map-----------------*/

int		nb_exit(char **map, char *file);
int		nb_player(char **map, char *file);
int		nb_collectible(char **map, char *file);
int		valid_char(t_mapdata mapdata);
int		valid_components(t_mapdata mapdata);

int		map_surrounded_by_walls(t_mapdata mapdata);
bool    flood_fill(t_mapdata *map, t_point curr, char **maze);
bool    has_valid_path(t_mapdata *mapdata);
int		line_length_equal(t_mapdata mapdata, char *file);
int		valid_file(int argc, char *file);
int		valid_map(char *file, t_mapdata *mapdata);

/*-------------------- Game Init --------------------*/

int		game_start(t_game *game);
void	init_images(t_game *game);
void	parse_chars(t_mapdata *mapdata, t_game *game, int width, int i, int j);
int		render(t_game *game, t_mapdata *mapdata);
void	loop_images(t_game *game);

int		handle_btnrealease(t_mapdata *mapdata);
int		handle_keypress(int keysym, t_mapdata *mapdata);

/*-------------------- Utils --------------------*/

void	matrix_delete(char **str);

#endif