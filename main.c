/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:23:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/14 14:53:09 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	mlx_loop(mlx);
	img = mlx_new_image(mlx, 1920, 1080);
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}*/
/*
int	main()
{
	int	i;
	char	**map;
	char	**map_1;
	char	**map_2;
	char	**map_3;
	char	**map_4;
	char	**map_5;
	char	*file;
	char	*file_1;
	char	*file_2;
	char	*file_3;
	char	*file_4;
	char	*file_5;

	i = 0;
	file = "maps/map_2.ber";
	file_1 = "maps_invalid/map_invalid_collectible.ber";
	file_2 = "maps_invalid/map_invalid_exit_2.ber";
	file_3 = "maps_invalid/map_invalid_exit.ber";
	file_4 = "maps_invalid/map_invalid_player_2.ber";
	file_5 = "maps_invalid/map_invalid_player.ber";
	map = read_map(file);
	map_1 = read_map(file_1);
	map_2 = read_map(file_2);
	map_3 = read_map(file_3);
	map_4 = read_map(file_4);
	map_5 = read_map(file_5);
	while (i < 5)
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\nCollectible %i\n", at_least_one_collectible(map_1, file_1));
	printf("\nOne exit %i\n", one_exit(map_2, file_2));
	printf("\nOne exit %i\n", one_exit(map_3, file_3));
	printf("\nOne player %i\n", one_player(map_4, file_4));
	printf("\nOne player %i\n", one_player(map_5, file_5));
	return (0);
}
*/
