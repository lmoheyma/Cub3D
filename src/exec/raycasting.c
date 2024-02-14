/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:10:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 15:07:58 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int raycasting(t_cub3d *cub)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		init_raycast(cub, x);
		dda(cub);
		dda2(cub);
		line_height(cub);
		update_textures(cub, x);
		x++;
	}
	return (0);
}

void init_raycast(t_cub3d *cub, int x)
{
	cub->cameraX = 2 * x / (double)WIDTH - 1;
	cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
	cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
	cub->mapX = (int)(cub->player->p_x);
	cub->mapY = (int)(cub->player->p_y);
	cub->deltaDistX = fabs(1 / cub->rayDirX);
	cub->deltaDistY = fabs(1 / cub->rayDirY);
}

void dda(t_cub3d *cub)
{
	if (cub->rayDirX < 0)
	{
		cub->stepX = -1;
		cub->sideDistX = (cub->player->p_x - cub->mapX) * cub->deltaDistX;
	}
	else
	{
		cub->stepX = 1;
		cub->sideDistX = (cub->mapX + 1.0 - cub->player->p_x) * cub->deltaDistX;	
	}
	if (cub-> rayDirY < 0)
	{
		cub->stepY = -1;
		cub->sideDistY = (cub->player->p_y - cub->mapY) * cub->deltaDistY;	
	}
	else
	{
		cub->stepY = 1;
		cub->sideDistY = (cub->mapY + 1.0 - cub->player->p_y) * cub->deltaDistY;
	}
}

void dda2(t_cub3d *cub)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub->sideDistX < cub->sideDistY)
		{
			cub->sideDistX += cub->deltaDistX;
			cub->mapX += cub->stepX;
			cub->side = 0;
		}
		else
		{
			cub->sideDistY += cub->deltaDistY;
			cub->mapY += cub->stepY;
			cub->side = 1;
		}
		if (cub->mapY < 0.25 || cub->mapX < 0.25 || cub->mapY > HEIGHT - 0.25 || cub->mapX > WIDTH - 1.25)
			break ;
		if (cub->vars->map[cub->mapY][cub->mapX] > '0')
			hit = 1;
	}
}

void line_height(t_cub3d *cub)
{
	if (cub->side == 0)
		cub->perpWallDist = (cub->sideDistX - cub->deltaDistX);
	else
		cub->perpWallDist = (cub->sideDistY - cub->deltaDistY);
	cub->lineHeight = (int)(HEIGHT / cub->perpWallDist);
	cub->drawStart = -(cub->lineHeight / 2) + (HEIGHT / 2);
	if (cub->drawStart < 0)
		cub->drawStart = 0;
	cub->drawEnd = (cub->lineHeight / 2) + (HEIGHT / 2);
	if (cub->drawEnd >= HEIGHT)
		cub->drawEnd = HEIGHT - 1;
	if (cub->side == 0)
		cub->wall_x = cub->player->p_y + cub->perpWallDist * cub->rayDirY;
	else
		cub->wall_x = cub->player->p_x + cub->perpWallDist * cub->rayDirX;
	cub->wall_x -= floor(cub->wall_x);
}
