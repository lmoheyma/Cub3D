/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:56:48 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 09:59:28 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	img_error(t_cub3d *cub)
{
	ft_putendl_fd("Error\nLoading assets", 1);
	// mlx_destroy_image(cub->ptr, cub->image);
	mlx_destroy_window(cub->ptr, cub->window);
	mlx_destroy_display(cub->ptr);
	free(cub->player);
	free(cub->ptr);
	free(cub->data);
	free(cub->param);
	free(cub->minimap);
	free_vars(cub->vars);
	exit(0);
}

void	setup_images(t_cub3d *cub)
{
	int	h;
	int	w;

	cub->xpm_void = mlx_xpm_file_to_image(cub->ptr, "./assets/map_void1gfhhf0.xpm",
			&w, &h);
	if (!cub->xpm_void)
		img_error(cub);
	cub->xpm_wall = mlx_xpm_file_to_image(cub->ptr, "./assets/map_wall10.xpm",
			&w, &h);
	if (!cub->xpm_wall)
		img_error(cub);
	cub->xpm_mndoor = mlx_xpm_file_to_image(cub->ptr, "./assets/door10.xpm", &w,
			&h);
	if (!cub->xpm_mndoor)
		img_error(cub);
	cub->xpm_player = mlx_xpm_file_to_image(cub->ptr,
			"./assets/red_player10.xpm", &w, &h);
	if (!cub->xpm_player)
		img_error(cub);
}

// void	setup_images(t_cub3d *cub)
// {
// 	int	h;
// 	int	w;

// 	cub->xpm_void = mlx_xpm_file_to_image(cub->ptr, "./assets/map_void10.xpm",
// 			&w, &h);
// 	if (!cub->xpm_void)
// 	{
// 		ft_putendl_fd("Error", 1);
// 		ft_putendl_fd("Loading assets", 1);
// 		close_window(cub);
// 	}
// 	cub->xpm_wall = mlx_xpm_file_to_image(cub->ptr, "./assets/map_wall10.xpm",
// 			&w, &h);
// 	if (!cub->xpm_wall)
// 	{
// 		ft_putendl_fd("Error", 1);
// 		ft_putendl_fd("Loading assets", 1);
// 		close_window(cub);
// 	}
// 	cub->xpm_mndoor = mlx_xpm_file_to_image(cub->ptr, "./assets/door10.xpm", &w,
// 			&h);
// 	if (!cub->xpm_mndoor)
// 	{
// 		ft_putendl_fd("Error", 1);
// 		ft_putendl_fd("Loading assets", 1);
// 		close_window(cub);
// 	}
// 	cub->xpm_player = mlx_xpm_file_to_image(cub->ptr,
// 			"./assets/red_player10.xpm", &w, &h);
// 	if (!cub->xpm_player)
// 		img_error(cub);
// }

void	get_player_pos(t_cub3d *cub)
{
	float	i;
	float	j;

	i = cub->player->p_x;
	j = cub->player->p_y;
	cub->minimap->player_x = i * MAP_SQUARE;
	cub->minimap->player_y = j * MAP_SQUARE;
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
				mlx_put_image_to_window(cub->ptr, cub->window, cub->xpm_void, j
					* MAP_SQUARE, i * MAP_SQUARE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub->ptr, cub->window, cub->xpm_player,
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
				mlx_put_image_to_window(cub->ptr, cub->window, cub->xpm_wall, j
					* MAP_SQUARE, i * MAP_SQUARE);
			if (map[i][j] == 'P' || map[i][j] == 'V')
				mlx_put_image_to_window(cub->ptr, cub->window, cub->xpm_mndoor,
					j * MAP_SQUARE, i * MAP_SQUARE);
			j++;
		}
		i++;
	}
}
