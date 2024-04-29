/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pass.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:04:55 by aishamagour       #+#    #+#             */
/*   Updated: 2024/04/21 16:25:59 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_pass(char **copy, int x, int y, t_play *game)
{
	if (game->exitcopy == -1 && game->collcopy == -1)
	{
		game->collcopy = game->c;
		game->exitcopy = game->e;
	}
	if (x < 0 || x > game->cols || y < 0
		|| y > game->rows || copy[y][x] == '1')
		return ;
	if (copy[y][x] == 'C')
		game->collcopy--;
	if (copy[y][x] == 'E')
	{
		game->exitcopy--;
		game->exit_x = x;
		game->exit_y = y;
	}
	copy[y][x] = '1';
	valid_pass(copy, x + 1, y, game);
	valid_pass(copy, x - 1, y, game);
	valid_pass(copy, x, y + 1, game);
	valid_pass(copy, x, y - 1, game);
}
