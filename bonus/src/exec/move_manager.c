/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:23:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 16:49:25 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	move_player(t_cub3d *cub)
{
	int	move;

	move = 0;
	if (cub->player->move_x == 1)
		move += move_right(cub);
	if (cub->player->move_x == -1)
		move += move_left(cub);
	if (cub->player->move_y == 1)
		move += move_up(cub);
	if (cub->player->move_y == -1)
		move += move_back(cub);
	if (cub->player->rotate != 0)
		move += rotate_player(cub, cub->player->rotate);
	return (move);
}

int	rotate_player(t_cub3d *cub, int rotate)
{
	int	move;

	if (rotate == 1)
		move = rotate_right(cub);
	else
		move = rotate_left(cub);
	return (move);
}
