/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:09:56 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/15 13:52:28 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	rotate_left(t_cub3d *cub, double speed)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(speed) - cub->dir_y * sin(speed);
	cub->dir_y = old_dir_x * sin(speed) + cub->dir_y * cos(speed);
	old_dir_y = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(speed) - cub->plane_y * sin(speed);
	cub->plane_y = old_dir_y * sin(speed) + cub->plane_y * cos(speed);
	return (1);
}

int	rotate_right(t_cub3d *cub, double speed)
{
	double	old_dir_x;
	double	old_dir_y;

	old_dir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(speed) - cub->dir_y * sin(speed);
	cub->dir_y = old_dir_x * sin(speed) + cub->dir_y * cos(speed);
	old_dir_y = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(speed) - cub->plane_y * sin(speed);
	cub->plane_y = old_dir_y * sin(speed) + cub->plane_y * cos(speed);
	return (1);
}
