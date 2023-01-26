/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:29:36 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/26 22:33:03 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

/*This function it will be call everytime that we have an event.
If the event is */
int		handle_keypress(int keysym, t_game *game)
{
	ft_printf("Keypress: %d\n", keysym);
	if (keysym == XK_Escape)
	{
		ft_printf("entrou BURRA");
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	else if (keysym == 'A' || keysym == 'S' || keysym == 'W' ||keysym == 'D')
	{
		ft_printf("entrou");
		move_player(game, keysym);
	}
	return (0);
}

/*This function it will be call everytime that we don't have an event 
and we need to close the window.*/
int		handle_btnrealease(t_game *game)
{
	//printf("Keyrelease: %d\n", keysym);
	mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	return (0);
}
