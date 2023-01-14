/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:37:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/14 22:15:35 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include <stdlib.h>

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

int	nb_exit(char **map, char *file);
int	nb_player(char **map, char *file);
int	nb_collectible(char **map, char *file);
int	valid_char(t_mapdata mapdata);
int	valid_components(t_mapdata mapdata);

int	map_surrounded_by_walls(t_mapdata mapdata);

#endif