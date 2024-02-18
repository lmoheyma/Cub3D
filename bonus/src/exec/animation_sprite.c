/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:08:58 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/18 23:02:16 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_animation(t_cub3d *cub)
{
	cub->frame_rate = 60;
	cub->animation_speed = 10;
	cub->frame_count = 0;
	cub->current_frame = 0;
}

void update_frame(t_cub3d *cub)
{
	cub->frame_count++;
	if (cub->frame_count >= cub->frame_rate / cub->animation_speed)
	{
		// printf("test\n");
		// printf("%d\n", cub->current_frame);
		cub->current_frame = (cub->current_frame + 1) % 7;
		cub->frame_count = 0;
	}
}

void update_animation(t_cub3d *cub)
{
	// printf("update\n");
	// if (cub->current_frame == 0)
	// 	display_sprite(cub, 5);
	if (cub->current_frame == 0)
	{
		display_sprite(cub, 6);
	}
	else if (cub->current_frame == 1)
		display_sprite(cub, 7);
	else if (cub->current_frame == 2)
		display_sprite(cub, 8);
	else if (cub->current_frame == 3)
		display_sprite(cub, 9);
	else if (cub->current_frame == 4)
		display_sprite(cub, 10);
	else if (cub->current_frame == 5)
		display_sprite(cub, 11);
	else if (cub->current_frame == 6)
		display_sprite(cub, 12);
}

void update_animation1(t_cub3d *cub)
{
	// printf("update\n");
	// if (cub->current_frame == 0)
	// 	display_sprite(cub, 5);
	if (cub->current_frame == 0)
	{
		display_sprite(cub, 13);
	}
	// else if (cub->current_frame == 1)
	// 	display_sprite(cub, 15);
	// else if (cub->current_frame == 2)
	// 	display_sprite(cub, 16);
	// else if (cub->current_frame == 3)
	// 	display_sprite(cub, 17);
	// else if (cub->current_frame == 4)
	// 	display_sprite(cub, 18);
	// else if (cub->current_frame == 5)
	// 	display_sprite(cub, 19);
	// else if (cub->current_frame == 6)
	// 	display_sprite(cub, 20);
}
