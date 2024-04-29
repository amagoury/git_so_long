/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:19:02 by aishamagour       #+#    #+#             */
/*   Updated: 2024/04/21 16:18:09 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	renderborders(t_play *game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (game->map[0][j])
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img[6],
			j * 64, 0 * 64);
		mlx_put_image_to_window(game->mlx, game->window, game->img[6],
			j * 64, (game->rows - 1) * 64);
		j++;
	}
	while (i < game->rows)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->img[6],
			0 * 64, i * 64);
		mlx_put_image_to_window(game->mlx, game->window, game->img[6],
			(game->cols - 1) * 64, i * 64);
		i++;
	}
}

static void	renderelements(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, game->img[9],
					j * 64, i * 64 - 10);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->img[game->frame / 30], j * 64, i * 64 - 10);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->img[8],
					j * 64, i * 64 - 10);
			j++;
		}
		j = 0;
		i++;
	}
}

void	rendermap(t_play *game)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	renderborders(game);
	while (i < game->rows - 1)
	{
		j = 1;
		while (j < game->cols - 1)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->img[6],
					j * 64, i * 64);
			else
				mlx_put_image_to_window(game->mlx, game->window, game->img[7],
					j * 64, i * 64);
			j++;
		}
		i++;
	}
	renderelements (game);
}
