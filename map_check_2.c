/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:09:31 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/14 22:43:43 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*In this function, I will verify if the map is sorrounded by walls*/

int	map_surrounded_by_walls(t_mapdata mapdata)
{
	int	i;
	int	j;

	i = 0;
	while(i < mapdata.size.y)
	{
		j = 0;
		while(mapdata.map[i][j] != '\0')
		{
			if (i == 0 && mapdata.map[i][j] != '1')
				return (0);
			if (j == 0 && mapdata.map[i][j] != '1')
				return (0);
			if (i == (mapdata.size.y - 1) && mapdata.map[i][j] != '1')
				return (0);
			if (j == (mapdata.size.x - 1) && mapdata.map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*In this function, I will verify if there is a path valid. I will use the flood_fill*/

int there_is_valid_path(char **map, t_point size, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
        return;
    if (map[row][col] != '1')
        return;
    there_is_valid_path(map, size, row -1, col);
    there_is_valid_path(map, size, row +1, col);
    there_is_valid_path(map, size, row, col - 1);
    there_is_valid_path(map, size, row, col + 1);
}

/*In this function, I will verify if the length of each line is equal*/

int	line_length_equal(t_mapdata mapdata, char *file)
{
	int	i;
	int	j;
	int line_count;
	int	column_count;

	line_count=count_lines_map(file);
	column_count = count_column_map(mapdata);
	i = 0;
	while(i < line_count)
	{
		j = 0;
		while(mapdata.map[i][j] != '\0')
		{
			if(mapdata.map[i][j + 1] == '\0' && j == (column_count - 1))
				break;
			else if(mapdata.map[i][j + 1] == '\0' && j != (column_count - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
	
}

/*In this function, I will verify the arguments and if the file is a .ber.*/

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("There is no arguments."));
	if (argc > 2)
		handle_errors("Only the first file would be used.");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("Map should be a .ber file"));
	return (1);
}

/*In this function, I will check all the requirements.*/

int	valid_map(int argc, char *file)
{
	t_mapdata	mapdata;

	mapdata = map(file);
	if (!valid_file(argc, file))
		return(0);
	if (!valid_components(mapdata))
		return(0);
	if(!map_surrounded_by_walls(mapdata))
		return (0);
	return (1);
}