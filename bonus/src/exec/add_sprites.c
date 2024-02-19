/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:57:42 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 01:16:38 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void add_torchs1( t_cub3d * cub, double x, double y, int start, int end)
{
	int i;
	int	j;

	i = start - 1;
	j = 6;
	while (++i < end)
		cub->sprite[i] = add_sprite(cub, x, y, j++);
}
