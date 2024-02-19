/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:58:15 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 11:58:48 by lmoheyma         ###   ########.fr       */
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
	sprite->collected = 0;
	return (sprite);
}

void	add_collectibles(t_cub3d *cub)
{
	cub->sprite[0] = add_sprite(cub, 25.7, 4.8, 5);
	cub->sprite[1] = add_sprite(cub, 20.3, 1.3, 5);
	cub->sprite[2] = add_sprite(cub, 16.7, 5.7, 5);
	cub->sprite[3] = add_sprite(cub, 12.3, 5.7, 5);
	cub->sprite[4] = add_sprite(cub, 15.7, 10.7, 5);
}

void	init_sprite(t_cub3d *cub)
{
	cub->collected_keys = 0;
	cub->s_param->z_buffer = (double *)ft_calloc(WIDTH, sizeof(double));
	if (!cub->s_param->z_buffer)
		close_window(cub);
	add_collectibles(cub);
	add_torchs1(cub, 20.02, 2.7, 5);
	add_torchs1(cub, 20.02, 4.3, 13);
}
