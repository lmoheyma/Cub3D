/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 16:50:44 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_texture_image(t_cub3d *cub, t_tmpimg *img, char *path)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->sl = 0;
	img->endian = 0;
	img->img = mlx_xpm_file_to_image(cub->ptr, path, &width, &height);
	if (!img->img)
		close_window(cub);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->sl,
			&img->endian);
}

int	*convert(t_cub3d *cub, char *path)
{
	t_tmpimg	img;
	int			*buffer;
	int			x;
	int			y;

	y = 0;
	img.img = NULL;
	init_texture_image(cub, &img, path);
	buffer = ft_calloc(1, sizeof(buffer) * SQUARE * SQUARE);
	if (!buffer)
		close_window(cub);
	while (y < SQUARE)
	{
		x = 0;
		while (x < SQUARE)
		{
			buffer[y * SQUARE + x] = img.addr[y * SQUARE + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(cub->ptr, img.img);
	return (buffer);
}

void	init_textures(t_cub3d *cub)
{
	t_assets	*assets;

	assets = cub->vars->assets;
	cub->param->textures = (int **)ft_calloc(5, sizeof(int *));
	if (!cub->param->textures)
		close_window(cub);
	cub->param->textures[0] = convert(cub, cub->vars->assets->no_link);
	cub->param->textures[1] = convert(cub, cub->vars->assets->so_link);
	cub->param->textures[2] = convert(cub, cub->vars->assets->ea_link);
	cub->param->textures[3] = convert(cub, cub->vars->assets->we_link);
	cub->param->c_color = rgb(ft_atoi(assets->c_link[0]),
			ft_atoi(assets->c_link[1]), ft_atoi(assets->c_link[2]));
	cub->param->f_color = rgb(ft_atoi(assets->f_link[0]),
			ft_atoi(assets->f_link[1]), ft_atoi(assets->f_link[2]));
}

void	init_textures_p(t_cub3d *cub)
{
	int	i;

	cub->param->textures_p = ft_calloc(HEIGHT + 1,
			sizeof(cub->param->textures_p));
	if (!cub->param->textures_p)
		close_window(cub);
	i = 0;
	while (i < HEIGHT)
	{
		cub->param->textures_p[i] = ft_calloc(WIDTH + 1,
				sizeof(cub->param->textures_p));
		if (!cub->param->textures_p[i])
			close_window(cub);
		i++;
	}
}

void	update_textures(t_cub3d *cub, int x)
{
	int	i;
	int	color;

	set_directions(cub);
	cub->param->x = (int)(cub->wall_x * SQUARE);
	if ((cub->side == 0 && cub->dirX < 0) || (cub->side == 1 && cub->dirX > 0))
		cub->param->x = SQUARE - cub->param->x - 1;
	cub->param->step = 1.0 * SQUARE / cub->lineHeight;
	cub->param->pos = (cub->drawStart - HEIGHT / 2 + cub->lineHeight / 2)
		* cub->param->step;
	i = cub->drawStart;
	while (i < cub->drawEnd)
	{
		cub->param->y = (int)cub->param->pos & (SQUARE - 1);
		cub->param->pos += cub->param->step;
		color = cub->param->textures[cub->directions][SQUARE * cub->param->y
			+ cub->param->x];
		if (cub->directions == 0 || cub->directions == 2)
			cub->param->color = (cub->param->color >> 1) & 8355711;
		if (color > 0)
			cub->param->textures_p[i][x] = color;
		i++;
	}
}
