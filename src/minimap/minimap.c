/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:56:48 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/12 16:27:09 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	get_player_pos(t_cub3d *cub)
{
	float	i;
	float	j;

	i = cub->player->p_x / SQUARE;
	j = cub->player->p_y / SQUARE;
	cub->minimap->player_x = i * MAP_SQUARE;
	cub->minimap->player_y = j * MAP_SQUARE;
}

void	setup_images(t_cub3d *cub)
{
	int	width;
	int	height;

	cub->xpm->xpm_wall = mlx_xpm_file_to_image(cub->ptr,
			"./assets/map_wall10.xpm", &width, &height);
	cub->xpm->xpm_void = mlx_xpm_file_to_image(cub->ptr,
			"./assets/map_void10.xpm", &width, &height);
	cub->xpm->xpm_player = mlx_xpm_file_to_image(cub->ptr,
			"./assets/red_player10.xpm", &width, &height);
}

void	show_minimap(t_cub3d *cub)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = cub->vars->map;
	get_player_pos(cub);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				mlx_put_image_to_window(cub->ptr, cub->window,
					cub->xpm->xpm_void, j * MAP_SQUARE, i * MAP_SQUARE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->ptr, cub->window, cub->xpm->xpm_player,
		cub->minimap->player_x - 5, cub->minimap->player_y - 5);
	show_minimap_wall(cub, map);
}

void	show_minimap_wall(t_cub3d *cub, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(cub->ptr, cub->window,
					cub->xpm->xpm_wall, j * MAP_SQUARE, i * MAP_SQUARE);
			j++;
		}
		i++;
	}
}
