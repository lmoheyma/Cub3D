/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:23:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 16:49:11 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	move_up(t_cub3d *cub)
{
	double	y_new;
	double	x_new;

	x_new = cub->player->p_x + cub->dirX * 0.2;
	y_new = cub->player->p_y + cub->dirY * 0.2;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
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
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
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
	if (cub->vars->map[(int)(y_new - cub->dirX
			* 0.1)][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)(x_new + cub->dirY
			* 0.1)] == '0')
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
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x = x_new;
		cub->player->p_y = y_new;
	}
	return (1);
}
