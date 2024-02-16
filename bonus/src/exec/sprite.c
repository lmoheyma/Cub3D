/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:18:38 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/16 19:17:14 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_sprite	*add_sprite(t_cub3d *cub, double x, double y, int texture)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprite)
		close_window(cub);
	sprite->x = x;
	sprite->y = y;
	sprite->texture = texture;
	return (sprite);
}

void add_torchs(t_cub3d * cub)
{
	cub->sprite[5] = add_sprite(cub, 30, 1.1, 6);
	cub->sprite[6] = add_sprite(cub, 30, 1.1, 7);
	// cub->sprite[7] = add_sprite(cub, 30, 1.1, 6);
	// cub->sprite[8] = add_sprite(cub, 30, 1.1, 6);
	// cub->sprite[9] = add_sprite(cub, 30, 1.1, 6);
	// cub->sprite[10] = add_sprite(cub, 30, 1.1, 6);
	// cub->sprite[11] = add_sprite(cub, 30, 1.1, 6);
}

void add_collectibles(t_cub3d *cub)
{
	cub->sprite[0] = add_sprite(cub, 30, 3, 5);
	cub->sprite[1] = add_sprite(cub, 16.7, 5.7, 5);
	cub->sprite[2] = add_sprite(cub, 17.5, 1.5, 5);
	cub->sprite[3] = add_sprite(cub, 4.5, 12.5, 5);
	cub->sprite[4] = add_sprite(cub, 12.5, 12.5, 5);
}

void	init_sprite(t_cub3d *cub)
{
	cub->param->nb_sprite = 12;
	cub->sprite = (t_sprite **)ft_calloc(cub->param->nb_sprite + 1,
			sizeof(t_sprite *));
	if (!cub->sprite)
		close_window(cub);
	cub->s_param->z_buffer = (double *)ft_calloc(WIDTH, sizeof(double));
	if (!cub->s_param->z_buffer)
		close_window(cub);
	add_collectibles(cub);
	// cub->sprite[5] = add_sprite(cub, 30, 1.1, 6);
	add_torchs(cub);
}

void sprite_data(t_cub3d *cub, int i)
{
	t_sprite_param *s_p;

	s_p = cub->s_param;
	s_p->sprite_x = cub->sprite[i]->x - cub->player->p_x;
	s_p->sprite_y = cub->sprite[i]->y - cub->player->p_y;
	s_p->inv_det = 1.0 / (cub->plane_x * cub->dir_y - cub->dir_x * cub->plane_y);
	s_p->transform_x = s_p->inv_det * (cub->dir_y * s_p->sprite_x - cub->dir_x * s_p->sprite_y);
	s_p->transform_y = s_p->inv_det * (-(cub->plane_y) * s_p->sprite_x + cub->plane_x * s_p->sprite_y);
	s_p->sprite_screen_x = (int)((WIDTH / 2) * (1 + s_p->transform_x / s_p->transform_y));
	s_p->sprite_height = abs((int)(HEIGHT / s_p->transform_y));
	s_p->draw_start_y = -(s_p->sprite_height) / 2 + HEIGHT / 2;
}

void data_draw_sprite(t_cub3d *cub)
{
	t_sprite_param *s_p;

	s_p = cub->s_param;
	if (s_p->draw_start_y < 0)
		s_p->draw_start_y = 0;
	s_p->draw_end_y = s_p->sprite_height / 2 + HEIGHT / 2;
	if (s_p->draw_end_y >= HEIGHT)
		s_p->draw_end_y = HEIGHT - 1;
	s_p->sprite_width = abs((int)(HEIGHT / s_p->transform_y));
	s_p->draw_start_x = -(s_p->sprite_width) / 2 + s_p->sprite_screen_x;
	if (s_p->draw_start_x < 0)
		s_p->draw_start_x = 0;
	s_p->draw_end_x = s_p->sprite_width / 2 + s_p->sprite_screen_x;
	if (s_p->draw_end_x >= WIDTH)
		s_p->draw_end_x = WIDTH - 1;
}

void draw_sprite(t_cub3d *cub, int stripe, int i)
{
	int color;
	int	y;
	int	d;
	t_sprite_param *s_p;

	s_p = cub->s_param;
	while (stripe < s_p->draw_end_x)
	{
		s_p->texture_x = (int)(256 * (stripe - (-s_p->sprite_width / 2 + s_p->sprite_screen_x)) * SQUARE / s_p->sprite_width) / 256;
		if (s_p->transform_y > 0 && stripe > 0 && stripe < WIDTH && s_p->transform_y < s_p->z_buffer[stripe])
		{
			y = s_p->draw_start_y;
			while (y < s_p->draw_end_y)
			{
				d = y * 256 - HEIGHT * 128 + s_p->sprite_height * 128;
				s_p->texture_y = ((d * SQUARE) / s_p->sprite_height) / 256;
				color = cub->param->textures[cub->sprite[i]->texture][SQUARE * s_p->texture_y + s_p->texture_x];
				if ((color & 0x00FFFFFF) != 0)
					cub->param->textures_p[y][stripe] = color;
				y++;
			}
		}
		stripe++;
	}
}

void	display_sprite(t_cub3d *cub, int index)
{
	int	stripe;
	t_sprite_param *s_p;

	s_p = cub->s_param;
	sprite_data(cub, index);
	data_draw_sprite(cub);
	stripe = s_p->draw_start_x;
	draw_sprite(cub, stripe, index);
}
