/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:42:38 by amagoury          #+#    #+#             */
/*   Updated: 2024/04/21 16:48:47 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "GNL/get_next_line_bonus.h"
# include "ft_printf.h"

typedef struct s_play
{
	char	**map;
	char	**map_cpy;
	char	collectibles;
	char	**map_said;
	int		e;
	int		c;
	int		p;
	int		x;
	int		y;
	int		exitcopy;
	int		collcopy;
	void	*mlx;
	void	*mlx_win;
	int		rows;
	int		cols;
	int		player;
	int		exits;
	int		coll;
	void	*window;
	int		frame;
	void	*pics;
	int		hight;
	int		whight;
	void	*img[10];
	void	*wall;
	int		exit_x;
	int		exit_y;
	int		control;
	int		flag;
	int		moves;
}	t_play;

typedef enum keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	W = 13,
	A= 0,
	S = 1,
	D = 2,
	ESC = 53
}	t_keys;

int			map_name(char *map);
char		**get_map_from_file(char *read_map, t_play *game);
void		get_map(char *read_map, t_play *game);
int			map_size(t_play *game);
int			check_wall(t_play *game);
void		count_charcters(t_play *game);
int			is_allowed(char c);
int			check_collctibles(t_play *game);
void		is_parsing(t_play *game, char *file);
int			closing_window(t_play *game);
void		free_map(t_play *game);
void		rendermap(t_play *game);
void		valid_pass(char **copy, int x, int y, t_play *game);
void		next_move(t_play *game, int x, int y);
int			joy_moves(int key, t_play *game);
void		exiting_game(t_play *game, int new_x, int new_y);
void		get_images(t_play *game);
void		exit_moves(t_play *game);
int			make_text(t_play *game);

#endif