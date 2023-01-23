/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:52:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/23 22:19:04 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*This function initiate the struct game.*/
/*Initializes the MLX library. Must be called before ANY other function. 
Will return NULL if initialization failed.*/
/*Creates a new window instance. It will return a window instance pointer. 
This should be saved for future reference.*/
int	game_start(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->window = mlx_new_window(game->mlx, game->window_size.x, game->window_size.y, "so_long");
	game->moves = 0;
	if (game->window == NULL)
	{
		free(game->window);
		return (0);
	}
	return (1);
}

/*This function initiate the images.*/
void	init_images(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, "11.xpm", &game->img.size.x, &game->img.size.y);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,"13.xpm" , &game->img.size.x, &game->img.size.y);
	game->img.ground = mlx_xpm_file_to_image(game->mlx, "10.xpm", &game->img.size.x, &game->img.size.y);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "8.xpm", &game->img.size.x, &game->img.size.y);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "12.xpm" , &game->img.size.x, &game->img.size.y);
}

/*In this funcion, I will take the game and mapdata. 
Then I will do a loop, where while exist mapdata, I will call the function parse_char, 
in order to build my map with the images.*/
int	render(t_game *game)
{
	int		i;
	int		j;
	int		width;

	if (game->window == NULL)
		return (0);
	i = 0;
	j = 0;
	width = 0;
	while (game->map.map[i])
	{
		while (j < game->map.size.x)
		{
			parse_chars(game, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (1);
}

/*This function takes the mapdata and put the image in the window*/
void	parse_chars(t_game *game, int width, int i, int j)
{
	if (game->map.map[i][j] == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall, width, i * IMG_SIZE);
	else if (game->map.map[i][j] == EMPTY)
		mlx_put_image_to_window(game->mlx, game->window, game->img.ground, width, i * IMG_SIZE);
	else if (game->map.map[i][j] == PLAYER)
		mlx_put_image_to_window(game->mlx, game->window, game->img.player, width, i * IMG_SIZE);
	else if (game->map.map[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit, width, i * IMG_SIZE);
	else if (game->map.map[i][j] == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->window, game->img.coin, width, i * IMG_SIZE);
}

/*mlx_loop
Loop over the given MLX pointer. 
Each hook that was registered prior to this will be called accordingly by order of registration.*/
/*mlx_loop_hook
Hook into the loop.*/
/*2 - KeyPress*/
/*1L<<0 - KeyPressMask*/

/*33 - ClientMessage*/
/*1L<<5 - LeaveWindowMask*/
void	loop_images(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, &game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game->window, ClientMessage, LeaveWindowMask, &handle_btnrealease, &game);
	mlx_loop(game->mlx);
}
