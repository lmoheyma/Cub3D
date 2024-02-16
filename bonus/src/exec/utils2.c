/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/16 04:41:35 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_image(t_cub3d *cub, t_tmpimg *img, int x, int y)
{
	if (cub->param->textures_p[y][x] > 0)
		put_pixel(img, x, y, cub->param->textures_p[y][x]);
	else if (y < HEIGHT / 2)
		put_pixel(img, x, y, cub->param->c_color);
	else if (y < HEIGHT - 1)
		put_pixel(img, x, y, cub->param->f_color);
}

void	init_image(t_cub3d *cub, t_tmpimg *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->sl = 0;
	img->endian = 0;
	img->img = mlx_new_image(cub->ptr, WIDTH, HEIGHT);
	if (!img->img)
		close_window(cub);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->sl,
			&img->endian);
}

void	create_frame(t_cub3d *cub)
{
	t_tmpimg	img;
	int			x;
	int			y;

	y = 0;
	img.img = NULL;
	init_image(cub, &img);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_image(cub, &img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->ptr, cub->window, img.img, 0, 0);
	mlx_destroy_image(cub->ptr, img.img);
}

void	set_directions(t_cub3d *cub)
{
	if (cub->side == 0)
	{
		if (cub->raydir_x < 0)
			cub->directions = 3;
		else
			cub->directions = 2;
	}
	else
	{
		if (cub->raydir_y > 0)
			cub->directions = 1;
		else
			cub->directions = 0;
	}
	if (cub->vars->map[cub->map_y][cub->map_x] == 'P')
		cub->directions = 4;
}
