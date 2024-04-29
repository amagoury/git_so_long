/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 11:44:20 by aishamagour       #+#    #+#             */
/*   Updated: 2024/04/21 20:10:07 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closing_window(t_play *game)
{
	mlx_destroy_image(game->mlx, game->img[0]);
	mlx_destroy_image(game->mlx, game->img[1]);
	mlx_destroy_image(game->mlx, game->img[2]);
	mlx_destroy_image(game->mlx, game->img[3]);
	mlx_destroy_image(game->mlx, game->img[4]);
	mlx_destroy_image(game->mlx, game->img[5]);
	mlx_destroy_image(game->mlx, game->img[6]);
	mlx_destroy_image(game->mlx, game->img[7]);
	mlx_destroy_image(game->mlx, game->img[8]);
	mlx_destroy_image(game->mlx, game->img[9]);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game);
	exit(0);
	return (0);
}

void	free_map(t_play *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	if (game->map_cpy)
	{
		i = 0;
		while (game->map_cpy[i] != NULL)
		{
			free(game->map_cpy[i]);
			i++;
		}
		free (game->map_cpy);
	}
}

static void	initialize(t_play *game)
{
	game->c = 0;
	game->e = 0;
	game->p = 0;
	game->y = 0;
	game->x = 0;
	game->collcopy = -1;
	game->exitcopy = -1;
	game->rows = 0;
	game->flag = 0;
}

int	main(int ac, char **av)
{
	t_play	game;

	if (ac != 2)
		(write(2, "No enough args\n", 15), exit (1));
	initialize(&game);
	is_parsing(&game, av[1]);
	game.moves = 0;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.cols * 64,
			game.rows * 64, "joy & her cats");
	get_images(&game);
	rendermap(&game);
	mlx_hook(game.window, 2, 0, joy_moves, &game);
	mlx_hook(game.window, 17, 0, closing_window, &game);
	mlx_loop_hook(game.mlx, make_text, &game);
	mlx_loop(game.mlx);
	return (0);
}
