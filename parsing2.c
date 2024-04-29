/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:06:00 by aishamagour       #+#    #+#             */
/*   Updated: 2024/04/24 17:59:36 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_allowed(char c)
{
	if (c != 'P' && c != 'C' && c != 'E' && c != '0' && c != '1')
		return (-1);
	return (1);
}

int	check_collctibles(t_play *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->rows)
	{
		while (game->map[i][j])
		{
			if (is_allowed(game->map[i][j]) == -1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	checkborders(t_play *game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (game->map[0][j])
	{
		if (game->map[0][j] != '1' || game->map[game->rows - 1][j] != '1')
			return (-1);
		j++;
	}
	while (i < game->rows - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}

void	is_parsing(t_play *game, char *file)
{
	int	i;

	i = 0;
	if (map_name(file) == -1)
		exit(1);
	game->map = get_map_from_file(file, game);
	if (map_size(game) == -1)
		(free_map(game), ft_putstr_fd("wrong size.\n", 2), exit (1));
	if (checkborders(game) == -1)
		(free_map(game), ft_putstr_fd("map not closed.\n", 2), exit (1));
	if (check_collctibles(game) == -1)
		(free_map(game), ft_putstr_fd("nsufficient tokens.\n", 2), exit (1));
	count_charcters(game);
	valid_pass(game->map_cpy, game->x, game->y, game);
	if (game->collcopy != 0 || game->exitcopy != 0)
		(free_map(game), ft_putstr_fd("no valid path.\n", 2), exit (1));
	while (game->map_cpy[i])
	{
		free(game->map_cpy[i]);
		i++;
	}
	free (game->map_cpy);
	game->map_cpy = NULL;
}

void	count_charcters(t_play *game)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (++i < game->rows)
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->c++;
			if (game->map[i][j] == 'E')
				game->e++;
			if (game->map[i][j] == 'P')
			{
				game->p++;
				game->x = j;
				game->y = i;
			}
			j++;
		}
		j = 0;
	}
	if (game->p != 1 || game->e != 1 || game->c < 1)
		(free_map(game), ft_putstr_fd("nsufficient tokens.\n", 2), exit(1));
}
