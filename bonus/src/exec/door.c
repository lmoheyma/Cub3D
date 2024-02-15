/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:15:30 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/15 13:57:23 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	dda2_door(t_cub3d *cub)
{
	while (1)
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
		if (cub->vars->map[cub->map_y][cub->map_x] == '1')
			return (0);
		else if (ft_strchr("PV", cub->vars->map[cub->map_y][cub->map_x]))
			return (1);
	}
	return (0);
}

void	do_door(char **map, int y, int x)
{
	if (map[y][x] == 'P')
		map[y][x] = 'V';
	else
		map[y][x] = 'P';
}

void	door_check(t_cub3d *cub)
{
	init_raycast(cub, WIDTH / 2);
	dda(cub);
	if (!dda2_door(cub))
		return ;
	line_height(cub);
	if (cub->perp_wall_dist < 1.5)
		do_door(cub->vars->map, cub->map_y, cub->map_x);
}
