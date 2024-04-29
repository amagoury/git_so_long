/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:43:47 by amagoury          #+#    #+#             */
/*   Updated: 2024/04/21 16:16:05 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_play *game)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	game->img[0] = mlx_xpm_file_to_image(game->mlx, "./img/cat0.xpm", &x, &y);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, "./img/cat1.xpm", &x, &y);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, "./img/cat2.xpm", &x, &y);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, "./img/cat3.xpm", &x, &y);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, "./img/cat4.xpm", &x, &y);
	game->img[5] = mlx_xpm_file_to_image(game->mlx, "./img/cat5.xpm", &x, &y);
	game->img[6] = mlx_xpm_file_to_image(game->mlx, "./img/water.xpm", &x, &y);
	game->img[7] = mlx_xpm_file_to_image(game->mlx, "./img/land.xpm", &x, &y);
	game->img[8] = mlx_xpm_file_to_image(game->mlx, "./img/house.xpm", &x, &y);
	game->img[9] = mlx_xpm_file_to_image(game->mlx, "./img/girl.xpm", &x, &y);
	game->frame = 0;
}

int	make_text(t_play *game)
{
	char	*str;

	rendermap (game);
	game->frame = (game->frame + 1) % (6 * 20);
	mlx_put_image_to_window(game->mlx, game->window, game->img[6], 0, 0);
	mlx_string_put(game->mlx, game->window, 8, 10, 0xFF00FF, "cats:");
	str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 50, 10, 0xFF00FF, str);
	free (str);
	return (0);
}
