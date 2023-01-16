/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/16 22:59:28 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*In this function, I will check all the requirements.*/

int	valid_map(int argc, char *file)
{
	t_mapdata	mapdata;

	if (!valid_file(argc, file))
		return(0);
	mapdata = map(file);
	if (!valid_components(mapdata))
		return(0);
	if(!map_surrounded_by_walls(mapdata))
	{
		matrix_delete(mapdata.map);
		return (0);
	}
	if(!line_length_equal(mapdata, file))
	{
		matrix_delete(mapdata.map);
		return (0);
	}
	if(!has_valid_path(&mapdata))
		return (0);
	return (1);
}

/*In the main, I will call the funtion valid map in order to check if the map is valid. 
Then, I will call the funtion game_start_map in order to fill the struct game.
To initiate a loop, we call the mlx_loop function with the mlx instance as only parameter,
Now for each frame it requires, it will call the function update with the parameter YourStruct. */

int	main(int argc, char **argv)
{
	t_game	*game;

	if(!valid_map(argc, argv[1]))
		return (0);
	if(!game_start(game, argc, argv[1]))
		return (0);
	mlx_hook(game->window, 2, 0, input, (void *)&game);
	mlx_loop_hook(game->mlx, update, (void *)&game);
	mlx_loop(game->mlx);
	return (0);
}
