/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:09:56 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 13:59:00 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	rotate_left(t_cub3d *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(-0.05) - cub->dir_y * sin(-0.05);
	cub->dir_y = old_dir_x * sin(-0.05) + cub->dir_y * cos(-0.05);
	old_plane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(-0.05) - cub->plane_y * sin(-0.05);
	cub->plane_y = old_plane_x * sin(-0.05) + cub->plane_y * cos(-0.05);
	return (1);
}

int	rotate_right(t_cub3d *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(0.05) - cub->dir_y * sin(0.05);
	cub->dir_y = old_dir_x * sin(0.05) + cub->dir_y * cos(0.05);
	old_plane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(0.05) - cub->plane_y * sin(0.05);
	cub->plane_y = old_plane_x * sin(0.05) + cub->plane_y * cos(0.05);
	return (1);
}
