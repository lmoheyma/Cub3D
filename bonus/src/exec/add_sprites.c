/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:57:42 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 10:33:12 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	add_torchs1(t_cub3d *cub, double x, double y, int start, int end)
{
	int	i;
	int	j;

	i = start - 1;
	j = 6;
	while (++i < end)
		cub->sprite[i] = add_sprite(cub, x, y, j++);
}
