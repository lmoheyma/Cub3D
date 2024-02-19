/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:08:58 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 10:01:50 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_animation(t_cub3d *cub)
{
	cub->frame_rate = 60;
	cub->animation_speed = 10;
	cub->frame_count = 0;
	cub->current_frame = 0;
}

void	update_frame(t_cub3d *cub)
{
	cub->frame_count++;
	if (cub->frame_count >= cub->frame_rate / cub->animation_speed)
	{
		cub->current_frame = (cub->current_frame + 1) % 7;
		cub->frame_count = 0;
	}
}

void	update_animation(t_cub3d *cub)
{
	if (cub->current_frame == 0)
	{
		display_sprite(cub, 6);
		display_sprite(cub, 14);
	}
	else if (cub->current_frame == 1)
	{
		display_sprite(cub, 7);
		display_sprite(cub, 15);
	}
	else if (cub->current_frame == 2)
	{
		display_sprite(cub, 8);
		display_sprite(cub, 16);
	}
	else if (cub->current_frame == 3)
	{
		display_sprite(cub, 9);
		display_sprite(cub, 17);
	}
	else if (cub->current_frame == 4)
	{
		display_sprite(cub, 10);
		display_sprite(cub, 18);
	}
	else if (cub->current_frame == 5)
	{
		display_sprite(cub, 11);
		display_sprite(cub, 19);
	}
	else if (cub->current_frame == 6)
	{
		display_sprite(cub, 12);
		display_sprite(cub, 20);
	}
}

void	display_barrel(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < 5)
		display_sprite(cub, i++);
}
