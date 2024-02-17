/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/17 19:15:05 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_texture_image(t_cub3d *cub, t_tmpimg *img, char *path)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->sl = 0;
	img->endian = 0;
	img->img = mlx_xpm_file_to_image(cub->ptr, path, &cub->size, &cub->size);
	if (!img->img)
	{
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("Loading assets", 1);
		close_window(cub);
	}
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
	buffer = ft_calloc(1, sizeof(buffer) * cub->size * cub->size);
	if (!buffer)
		close_window(cub);
	while (y < cub->size)
	{
		x = 0;
		while (x < cub->size)
		{
			buffer[y * cub->size + x] = img.addr[y * cub->size + x];
			x++;
		}
		y++;
	}
	cub->size = 64;
	mlx_destroy_image(cub->ptr, img.img);
	return (buffer);
}

void add_torchs_textures(t_cub3d *cub)
{
	cub->param->textures[6] = convert(cub, "./assets/torch/torch1.xpm");
	cub->param->textures[7] = convert(cub, "./assets/torch/torch2.xpm");
	cub->param->textures[8] = convert(cub, "./assets/torch/torch3.xpm");
	cub->param->textures[9] = convert(cub, "./assets/torch/torch4.xpm");
	cub->param->textures[10] = convert(cub, "./assets/torch/torch5.xpm");
	cub->param->textures[11] = convert(cub, "./assets/torch/torch6.xpm");
	cub->param->textures[12] = convert(cub, "./assets/torch/torch7.xpm");
	cub->param->textures[13] = convert(cub, "./assets/torch/torch8.xpm");
}

void	init_textures(t_cub3d *cub)
{
	t_assets	*assets;

	assets = cub->vars->assets;
	cub->param->textures = (int **)ft_calloc(15, sizeof(int *));
	if (!cub->param->textures)
		close_window(cub);
	cub->param->textures[0] = convert(cub, cub->vars->assets->no_link);
	cub->param->textures[1] = convert(cub, cub->vars->assets->so_link);
	cub->param->textures[2] = convert(cub, cub->vars->assets->ea_link);
	cub->param->textures[3] = convert(cub, cub->vars->assets->we_link);
	cub->param->textures[4] = convert(cub, "./assets/door2.xpm");
	cub->param->textures[5] = convert(cub, "./assets/key.xpm");
	cub->param->c_color = rgb(ft_atoi(assets->c_link[0]),
			ft_atoi(assets->c_link[1]), ft_atoi(assets->c_link[2]));
	cub->param->f_color = rgb(ft_atoi(assets->f_link[0]),
			ft_atoi(assets->f_link[1]), ft_atoi(assets->f_link[2]));
	// cub->param->textures[14] = convert(cub, "./assets/sky1.xpm");
	// cub->param->textures[7] = convert(cub, "./assets/wall_1.xpm");
	// add_torchs_textures(cub);
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
	cub->param->x = (int)(cub->wall_x * cub->size);
	if ((cub->side == 0 && cub->dir_x < 0) || (cub->side == 1
			&& cub->dir_x > 0))
		cub->param->x = cub->size - cub->param->x - 1;
	cub->param->step = 1.0 * cub->size / cub->line_height;
	cub->param->pos = (cub->draw_start - HEIGHT / 2 + cub->line_height / 2)
		* cub->param->step;
	i = cub->draw_start;
	while (i < cub->draw_end)
	{
		cub->param->y = (int)cub->param->pos & (cub->size - 1);
		cub->param->pos += cub->param->step;
		color = cub->param->textures[cub->directions][cub->size * cub->param->y
			+ cub->param->x];
		if (cub->directions == 0 || cub->directions == 2)
			cub->param->color = (cub->param->color >> 1) & 8355711;
		if (color > 0)
			cub->param->textures_p[i][x] = color;
		i++;
	}
	cub->s_param->z_buffer[x] = cub->perp_wall_dist;
}
