/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:18:15 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/13 21:24:48 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*Function to count the number of lines in the map file*/

int	count_lines_map(char *file)
{
	
}

/*Function to allocate memory in the array map. 
I use the funtion count_lines_map in order to allocate memory.*/

char	**allocate_memory_to_map(char *file)
{
	
}

/*This function will use the function allocate_memory_to_map in order to have the array **map with memory.
Then, I will use the function get next line in order to save each line in the map array*/

char	**read_map(char *file)
{
	
}