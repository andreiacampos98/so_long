/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:34:03 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/23 21:42:27 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*This function it will check if the next position is a wall*/
int	check_next_positions(t_game *game, char move, char character_next_position)
{
	if((move == 'w' && game->map.map[game->map.player_position.x][game->map.player_position.y + 1] == character_next_position)
		|| (move == 's' && game->map.map[game->map.player_position.x][game->map.player_position.y - 1] == character_next_position)
		|| (move == 'a' && game->map.map[game->map.player_position.x - 1][game->map.player_position.y] == character_next_position)
		|| (move == 'd' && game->map.map[game->map.player_position.x + 1][game->map.player_position.y] == character_next_position))
		return (1);
	return (0);		
}

/*This function it will count the collectables that already catch.*/
void	count_collectables_catches(t_game *game, char move)
{
	if((move == 'w' && game->map.map[game->map.player_position.x][game->map.player_position.y + 1] == COLLECTABLE)
		|| (move == 's' && game->map.map[game->map.player_position.x][game->map.player_position.y - 1] == COLLECTABLE)
		|| (move == 'a' && game->map.map[game->map.player_position.x - 1][game->map.player_position.y] == COLLECTABLE)
		|| (move == 'd' && game->map.map[game->map.player_position.x + 1][game->map.player_position.y] == COLLECTABLE))
		game->collect++;
}

/*This funtion it will quit the game when the player found the exit and have collect
all the colectable.*/
int	win_game(t_game *game)
{
	if (game->map.can_exit == 1)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
		return (1);
	}
	else
		return (0);
}

/*This function it will be call everytime that the user click on ASDW.
If the next position is a wall or the next position is an exit and 
there is collectible, the function return 0.*/
/*The number of steps should increase. I will call the function count_ollectables_catches.*/
/*If the number of collectables is equal to the original number for collectables,
we will change the value of can_exit for 1.*/
/*For each move, we will change the position*/
/*If can_exit = 1 and the position that we are is exit, we will call the funtion win_game.*/
/*Then we will put the player in that position.*/
void	move_player(t_game *game, char move)
{
	if(check_next_positions(game, move, WALL) == 1 || 
		(check_next_positions(game, move, EXIT) == 1 && game->map.can_exit == 0))
		return ;
	game->moves++;
	count_collectables_catches(game, move);
	if(game->collect != game->map.collect)
		game->map.can_exit = 1;
	game->map.map[game->map.player_position.x][game->map.player_position.y] = WALL;
	if (move == 'd')
		game->map.player_position.x++;
	else if (move == 'a')
		game->map.player_position.x--;
	else if (move == 's')
		game->map.player_position.y++;
	else if (move == 'w')
		game->map.player_position.y--;
	if (game->map.can_exit == 1 && game->map.map[game->map.player_position.x][game->map.player_position.y] == EXIT)
		win_game(game);
	game->map.map[game->map.player_position.x][game->map.player_position.y] = PLAYER;
}

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.ground);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_display(game->mlx);
}