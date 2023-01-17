/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:37:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/17 22:02:12 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdbool.h>

# define P "imgs/mario_3.png"
# define W "imgs/wall_1.png"
# define E "imgs/mario_3.png"
# define C "imgs/coin_1.png"
# define EN "imgs/flower_1.png"
# define G "imgs/flower_1.png"

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

typedef struct s_img
{
	void			*wall;  
	void			*player;
	void			*exit;  
	void			*ground; 
	void			*coin;
	t_point			size;  
}	t_img;

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
int		valid_map(int argc, char *file);

/*-------------------- Game Init --------------------*/

int	game_start(t_game *game);
int	update(t_game *game);
int	input(int key, t_game *game);

/*-------------------- Utils --------------------*/

void	matrix_delete(char **str);

#endif