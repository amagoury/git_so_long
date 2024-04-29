/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:59:04 by amagoury          #+#    #+#             */
/*   Updated: 2024/04/21 16:47:41 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exiting_game(t_play *game, int new_x, int new_y)
{
	(void) new_x;
	(void) new_y;
	if (game->c == 0)
		closing_window(game);
	else
		game->flag = 1;
}
