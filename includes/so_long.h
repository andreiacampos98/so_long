/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:37:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/16 23:31:16 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct s_tile
{
	t_components	type;  //type can be: EMPTY, WALL, COLLECTABLE, EXIT, PLAYER, ENEMY or FOLLOWER.
	t_components	og_type; //original type, is used to reset the game.
	t_point			position;  //defines the pixel coordinates of the tile to be drawn in the window
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_game
{
	void			*mlx;		// pointer to the mlx
	void			*window;	// pointer to the window
	t_point			wndw_size;	// window size

	t_tile			**tilemap;	// 2D tile table

	t_player		player;		// struct with info about the player: current tile, animation frames, counter and images

	int				og_collects;	// original collectable to be able to reset
	int				collects;	// current value, reducing one each time you pick up one
	int				moves;		// moves counter, adding one each time you spend a turn

	t_enemy			*enemy_list;	// list of enemy structs
	
	// sprites/images
	t_point			img_size;
	t_wall_img		wall_imgs;	// struct with all nine wall images
	t_collect_img	collects_imgs;	// struct with info about the collectables animation.
	t_enemy_img		enemy_imgs;	// struct with the animation info of the two type of enemies
	void			*door_open_img;	// images for the door
	void			*door_close_img;
	t_effect		effect;		// struct with the particle effect animation
	void			*red_panel;	// panels
	void			*white_panel;

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
int		valid_map(int argc, char *file);

/*-------------------- Game Init --------------------*/

int	game_start(t_game *game, int argc, char *argv);
int	update(t_game *game);
int	input(int key, t_game *game);

/*-------------------- Utils --------------------*/

void	matrix_delete(char **str);

#endif