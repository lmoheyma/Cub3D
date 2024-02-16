/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:10:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/16 03:48:11 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	raycasting(t_cub3d *cub)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_raycast(cub, x);
		floor_ceiling(cub, x);
		dda(cub);
		dda2(cub);
		line_height(cub);
		update_textures(cub, x);
		// display_sprite(cub);
		x++;
	}
	return (0);
}

void	init_raycast(t_cub3d *cub, int x)
{
	cub->camera_x = 2 * x / (double)WIDTH - 1;
	cub->raydir_x = cub->dir_x + cub->plane_x * cub->camera_x;
	cub->raydir_y = cub->dir_y + cub->plane_y * cub->camera_x;
	cub->map_x = (int)(cub->player->p_x);
	cub->map_y = (int)(cub->player->p_y);
	cub->delta_dist_x = fabs(1 / cub->raydir_x);
	cub->delta_dist_y = fabs(1 / cub->raydir_y);
}

void	dda(t_cub3d *cub)
{
	if (cub->raydir_x < 0)
	{
		cub->step_x = -1;
		cub->side_dist_x = (cub->player->p_x - cub->map_x) * cub->delta_dist_x;
	}
	else
	{
		cub->step_x = 1;
		cub->side_dist_x = (cub->map_x + 1.0 - cub->player->p_x)
			* cub->delta_dist_x;
	}
	if (cub->raydir_y < 0)
	{
		cub->step_y = -1;
		cub->side_dist_y = (cub->player->p_y - cub->map_y) * cub->delta_dist_y;
	}
	else
	{
		cub->step_y = 1;
		cub->side_dist_y = (cub->map_y + 1.0 - cub->player->p_y)
			* cub->delta_dist_y;
	}
}

void	dda2(t_cub3d *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->side_dist_x < cub->side_dist_y)
		{
			cub->side_dist_x += cub->delta_dist_x;
			cub->map_x += cub->step_x;
			cub->side = 0;
		}
		else
		{
			cub->side_dist_y += cub->delta_dist_y;
			cub->map_y += cub->step_y;
			cub->side = 1;
		}
		if (cub->map_y < 0.25 || cub->map_x < 0.25 || cub->map_y > HEIGHT - 0.25
			|| cub->map_x > WIDTH - 1.25)
			break ;
		if (ft_strchr("1P", cub->vars->map[cub->map_y][cub->map_x]))
			hit = 1;
	}
}

void	line_height(t_cub3d *cub)
{
	if (cub->side == 0)
		cub->perp_wall_dist = (cub->side_dist_x - cub->delta_dist_x);
	else
		cub->perp_wall_dist = (cub->side_dist_y - cub->delta_dist_y);
	cub->line_height = (int)(HEIGHT / cub->perp_wall_dist);
	cub->draw_start = -(cub->line_height / 2) + (HEIGHT / 2);
	if (cub->draw_start < 0)
		cub->draw_start = 0;
	cub->draw_end = (cub->line_height / 2) + (HEIGHT / 2);
	if (cub->draw_end >= HEIGHT)
		cub->draw_end = HEIGHT - 1;
	if (cub->side == 0)
		cub->wall_x = cub->player->p_y + cub->perp_wall_dist * cub->raydir_y;
	else
		cub->wall_x = cub->player->p_x + cub->perp_wall_dist * cub->raydir_x;
	cub->wall_x -= floor(cub->wall_x);
}
