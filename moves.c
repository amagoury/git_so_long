/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:16:21 by aishamagour       #+#    #+#             */
/*   Updated: 2024/04/21 16:17:22 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	next_move(t_play *game, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = game->x + x;
	next_y = game->y + y;
	if (game->map[next_y][next_x] == '1')
		return ;
	if (game->map[next_y][next_x] == 'C')
		game->c--;
	exit_moves(game);
	if (game->map[next_y][next_x] == 'E')
		exiting_game(game, next_x, next_y);
	game->x = next_x;
	game->y = next_y;
	game->map[game->y][game->x] = 'P';
	mlx_put_image_to_window (game->mlx, game->window, game->img[9],
		game->x * 64, game->y * 64);
	ft_printf("joy steps%d \n", ++(game->moves));
}

void	exit_moves(t_play *game)
{
	if (game->flag == 1)
	{
		game->map[game->y][game->x] = 'E';
		mlx_put_image_to_window(game->mlx, game->window, game->img[7],
			game->x * 64, game->y * 64);
		mlx_put_image_to_window(game->mlx, game->window, game->img[8],
			game->x * 64, game->y * 64 - 10);
		game->flag = 0;
	}
	else
	{
		game->map[game->y][game->x] = '0';
		mlx_put_image_to_window(game->mlx, game->window, game->img[7],
			game->x * 64, game->y * 64);
	}
}

int	joy_moves(int key, t_play *game)
{
	if (key == 13 || key == 126)
		next_move (game, 0, -1);
	if (key == 1 || key == 125)
		next_move(game, 0, 1);
	if (key == 0 || key == 123)
		next_move (game, -1, 0);
	if (key == 2 || key == 124)
		next_move (game, 1, 0);
	if (key == 53)
		closing_window(game);
	return (0);
}
