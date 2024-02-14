/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:23:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 12:50:29 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int move_player(t_cub3d *cub)
{
	int move;

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

int rotate_player(t_cub3d *cub, int rotate)
{
	int	move;
	
	if (rotate == 1)
		move = rotate_right(cub);
	else
		move = rotate_left(cub);
	return (move);
}

int	move_up(t_cub3d *cub)
{
	double	y_new;
	double	x_new;
	
	x_new = cub->player->p_x + cub->dirX * 0.2;
	y_new = cub->player->p_y + cub->dirY * 0.2;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0' && cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x += cub->dirX * 0.2;
		cub->player->p_y += cub->dirY * 0.2;
	}
	return (1);
}

int	move_back(t_cub3d *cub)
{
	double	y_new;
	double	x_new;
	
	x_new = cub->player->p_x - cub->dirX * 0.2;
	y_new = cub->player->p_y - cub->dirY * 0.2;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0' && cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x -= cub->dirX * 0.2;
		cub->player->p_y -= cub->dirY * 0.2;
	}
	return (1);
}

int	move_left(t_cub3d *cub)
{
	double	y_new;
	double	x_new;
	
	x_new = cub->player->p_x + cub->dirY * 0.1;
	y_new = cub->player->p_y - cub->dirX * 0.1;
	if (cub->vars->map[(int)(y_new - cub->dirX * 0.1)][(int)cub->player->p_x] == '0' && cub->vars->map[(int)cub->player->p_y][(int)(x_new + cub->dirY * 0.1)] == '0')
	{
		cub->player->p_x = x_new;
		cub->player->p_y = y_new;
	}
	return (1);
}

int	move_right(t_cub3d *cub)
{
	double	y_new;
	double	x_new;
	
	x_new = cub->player->p_x - cub->dirY * 0.1;
	y_new = cub->player->p_y + cub->dirX * 0.1;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0' && cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x = x_new;
		cub->player->p_y = y_new;
	}
	return (1);
}
