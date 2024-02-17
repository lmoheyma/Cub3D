/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:08:58 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/17 00:20:46 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void check_sprite(t_cub3d *cub)
{
	int	i;
	// cub->sprite[i]->collected == 0 && 
	i = 0;
	while (i < cub->param->nb_sprite && cub->sprite[i])
	{
		if (((int)(cub->sprite[i]->x) != (int)(cub->player->p_x) || (int)(cub->sprite[i]->y) != (int)(cub->player->p_y)))
		{
			display_sprite(cub, i);
		}
		else
		{
			if (!cub->sprite[i]->collected)
				cub->collected_keys++;
			cub->sprite[i]->collected = 1;
		}
		i++;
	}
}
