/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:23:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 14:00:58 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	move_up(t_cub3d *cub)
{
	double	y_new;
	double	x_new;

	x_new = cub->player->p_x + cub->dir_x * 0.1;
	y_new = cub->player->p_y + cub->dir_y * 0.1;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x += cub->dir_x * 0.1;
		cub->player->p_y += cub->dir_y * 0.1;
	}
	return (1);
}

int	move_back(t_cub3d *cub)
{
	double	y_new;
	double	x_new;

	x_new = cub->player->p_x - cub->dir_x * 0.1;
	y_new = cub->player->p_y - cub->dir_y * 0.1;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x -= cub->dir_x * 0.1;
		cub->player->p_y -= cub->dir_y * 0.1;
	}
	return (1);
}

int	move_left(t_cub3d *cub)
{
	double	y_new;
	double	x_new;

	x_new = cub->player->p_x + cub->dir_y * 0.05;
	y_new = cub->player->p_y - cub->dir_x * 0.05;
	if (cub->vars->map[(int)(y_new - cub->dir_x
			* 0.05)][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)(x_new + cub->dir_y
			* 0.05)] == '0')
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

	x_new = cub->player->p_x - cub->dir_y * 0.05;
	y_new = cub->player->p_y + cub->dir_x * 0.05;
	if (cub->vars->map[(int)y_new][(int)cub->player->p_x] == '0'
		&& cub->vars->map[(int)cub->player->p_y][(int)x_new] == '0')
	{
		cub->player->p_x = x_new;
		cub->player->p_y = y_new;
	}
	return (1);
}
