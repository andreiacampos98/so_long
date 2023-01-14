/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build_tile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:42:40 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/14 10:28:41 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "includes/so_long.h"

/*The function generate the tile filled according to map.
For each point in the map, I will check the tile's component(1, C, P, E, H, V, F), 
I will add information to tile about if is a player, collectable or enemy.
*/

