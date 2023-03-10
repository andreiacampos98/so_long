/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:56:32 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/29 12:09:13 by anaraujo         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	matrix_delete(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_exit(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		free(game->map.map[y]);
		y++;
	}
	free(game->map.map);
	mlx_destroy_window(game->mlx, game->window);
	destroy_images(game);
	exit(1);
	return (0);
}