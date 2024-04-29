/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:49:22 by amagoury          #+#    #+#             */
/*   Updated: 2024/04/21 16:43:50 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(char *map)
{
	if ((ft_strncmp(&map[ft_strlen(map)] - 4, ".ber", 4)) != 0)
	{
		write(2, "Woops\n", 6);
		return (-1);
	}
	return (1);
}

void	get_map(char *read_map, t_play *game)
{
	int		i;
	char	*lines;
	int		fd;

	i = 1;
	game->rows = 0;
	fd = open(read_map, O_RDONLY);
	if (fd == -1)
		(write(2, "Couldn't open file\n", 19), exit(1));
	lines = get_next_line(fd);
	while (lines)
	{
		game->rows++;
		free (lines);
		lines = get_next_line(fd);
	}
	free (lines);
	close (fd);
}

char	**get_map_from_file(char *read_map, t_play *game)
{
	int		i;
	int		fd;
	char	**map;

	get_map (read_map, game);
	map = malloc(sizeof(char *) * (game->rows + 1));
	game->map_cpy = malloc(sizeof(char *) * (game->rows + 1));
	fd = open(read_map, O_RDONLY);
	i = -1;
	while (++i < game->rows)
	{
		map[i] = ft_strtrim(get_next_line(fd), "\n");
		game->map_cpy[i] = ft_strdup(map[i]);
	}
	map[i] = NULL;
	game->map_cpy[i] = NULL;
	close (fd);
	return (map);
}

int	map_size(t_play *game)
{
	int	i;
	int	temp;

	i = 0;
	game->cols = (int)ft_strlen(game->map[0]);
	if (game->cols < 3 || game->rows < 3)
		return (-1);
	while (i < game->rows)
	{
		temp = (int)ft_strlen(game->map[i]);
		if (temp != game->cols)
			return (-1);
		i++;
	}
	if (game->rows * game->cols < 15)
		return (-1);
	return (1);
}

int	check_wall(t_play *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (-1);
		if (game->map[game->hight - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i < game->rows)
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->whight - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}
