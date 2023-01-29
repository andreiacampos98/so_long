/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_moves->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:59:48 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/29 11:57:28 by anaraujo         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_nb_moves(t_game **game)
{
	char	*number;
	char	*text;

	(*game)->moves++;
	number = ft_itoa((*game)->moves);
	text = ft_strjoin("Moves: ", number);
	mlx_string_put((*game)->mlx, (*game)->window, 5, 10, 0xfffffff, text);
	free(text);
	free(number);
}