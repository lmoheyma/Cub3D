/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:09:56 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 15:49:06 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	rotate_left(t_cub3d *cub)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(-0.05) - cub->dirY * sin(-0.05);
	cub->dirY = oldDirX * sin(-0.05) + cub->dirY * cos(-0.05);
	oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(-0.05) - cub->planeY * sin(-0.05);
	cub->planeY = oldPlaneX * sin(-0.05) + cub->planeY * cos(-0.05);
	return (1);
}

int	rotate_right(t_cub3d *cub)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(0.05) - cub->dirY * sin(0.05);
	cub->dirY = oldDirX * sin(0.05) + cub->dirY * cos(0.05);
	oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(0.05) - cub->planeY * sin(0.05);
	cub->planeY = oldPlaneX * sin(0.05) + cub->planeY * cos(0.05);
	return (1);
}
