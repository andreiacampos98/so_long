/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:37:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/25 18:33:40 by anaraujo         ###   ########.fr       */
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

# define IMG_SIZE 48
# define A 97
# define D 100
# define S 115
# define W 119
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_mapdata
{
	char	**map;
	t_point	size;
	t_point	player_position;
	int		player;
	int		exit;
	int		collect;
	int		can_exit;
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
	t_point			window_size;
	t_mapdata		map;
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
int		valid_map(char *file, t_mapdata mapdata);

/*-------------------- Game Init --------------------*/

int		game_start(t_game *game);
void	init_images(t_game *game);
void	parse_chars(t_game *game, int width, int i, int j);
int		render(t_game *game);
void	loop_images(t_game *game);

int		handle_btnrealease(t_game *game);
int		handle_keypress(int keysym, t_game *game);

int		check_next_positions(t_game *game, char move, char character_next_position);
void	count_collectables_catches(t_game *game, char move);
int		win_game(t_game *game);

void	move_player(t_game *game, char move);
void	destroy_images(t_game *game);

/*-------------------- Utils --------------------*/

void	matrix_delete(char **str);

#endif