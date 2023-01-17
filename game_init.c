/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:52:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/17 22:15:32 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

void	parse_chars(t_mapdata *mapdata, t_game *game, int width, int i, int j)
{
	if (mapdata->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img.wall,
			width, i * IMG_SIZE);
	else if (mapdata->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img.ground,
			width, i * IMG_SIZE);
	else if (mapdata->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->img.player,
			width, i * IMG_SIZE);
	else if (mapdata->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img.exit,
			width, i * IMG_SIZE);
	else if (mapdata->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img.coin,
			width, i * IMG_SIZE);
}

int	render(t_game *game, t_mapdata *mapdata)
{
	int		i;
	size_t	j;
	int		width;

	if (game->window == NULL)
		return (0);
	i = 0;
	j = 0;
	width = 0;
	while (mapdata->map[i])
	{
		while (mapdata->map[i] && mapdata->map[i][j] != '\n')
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
	game->window = mlx_new_window(game->mlx, game->wndw_size.x, game->wndw_size.y, "so_long");
	if (game->window == NULL)
	{
		matrix_delete(game->window);
		retunr (0);
	}
	return (1);
}

void	init_images(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, P, &game->img.size.x, &game->img.size.y);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, E, &game->img.size.x, &game->img.size.y);
	game->img.ground = mlx_xpm_file_to_image(game->mlx, G, &game->img.size.x, &game->img.size.y);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, W, &game->img.size.x, &game->img.size.y);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, C, &game->img.size.x, &game->img.size.y);
}

void	loop_images(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, &game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game->win, ClientMessage, LeaveWindowMask,
		&handle_btnrealease, &game);
	mlx_loop(game->mlx);
}

int	update(t_game *game)
{
	
}

int	input(int key, t_game *game)
{
	
}