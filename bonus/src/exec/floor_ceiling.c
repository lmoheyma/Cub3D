/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:18:36 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/17 16:00:43 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_values(t_cub3d *cub)
{
	cub->f_c->raydir_x0 = cub->dir_x - cub->plane_x;
	cub->f_c->raydir_y0 = cub->dir_y - cub->plane_y;
	cub->f_c->raydir_x1 = cub->dir_x - cub->plane_x;
	cub->f_c->raydir_y1 = cub->dir_y - cub->plane_y;
}

void	fill_buffer(t_cub3d *cub, int y)
{
	int	color;
	int	x;
	
	x = 0;
	while (x < WIDTH)
	{
		cub->f_c->cell_x = (int)cub->f_c->floor_x;
		cub->f_c->cell_y = (int)cub->f_c->floor_y;
		cub->f_c->t_x = (int)(SQUARE * (cub->f_c->floor_x - cub->f_c->cell_x)) & (SQUARE - 1);
		cub->f_c->t_y = (int)(SQUARE * (cub->f_c->floor_y - cub->f_c->cell_y)) & (SQUARE - 1);
		cub->f_c->floor_x += cub->f_c->floor_step_x;
		cub->f_c->floor_y += cub->f_c->floor_step_y;
		color = cub->param->textures[0][SQUARE * cub->f_c->t_y + cub->f_c->t_x];
		color = (color >> 1) & 8355711;
		cub->param->textures_p[y][x] = color;
		color = cub->param->textures[14][SQUARE * cub->f_c->t_y + cub->f_c->t_x];
		color = (color >> 1) & 8355711;
		cub->param->textures_p[HEIGHT - y - 1][x] = color;
		x++;
	}
}

void	floor_ceiling(t_cub3d *cub)
{
	int	p;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		init_values(cub);
		p = y - HEIGHT / 2;
		cub->f_c->pos_z = 0.5 * HEIGHT;
		cub->f_c->row_distance = cub->f_c->pos_z / p;
		cub->f_c->floor_step_x = cub->f_c->row_distance * (cub->f_c->raydir_x1 - cub->f_c->raydir_x0) / WIDTH;
		cub->f_c->floor_step_y = cub->f_c->row_distance * (cub->f_c->raydir_y1 - cub->f_c->raydir_y0) / WIDTH;
		cub->f_c->floor_x = cub->player->p_x + cub->f_c->row_distance * cub->f_c->raydir_x0;
		cub->f_c->floor_y = cub->player->p_y + cub->f_c->row_distance * cub->f_c->raydir_y0;
		fill_buffer(cub, y);
		y++;
	}
}
