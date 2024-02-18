/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:57:42 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/18 22:54:50 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void add_torchs1( t_cub3d * cub, double x, double y, int start, int end)
{
	int i;

	i = start - 1;
	while (++i < end)
	{
		cub->sprite[i] = add_sprite(cub, x, y, i + 1);
		printf("%d\n", i);
	}
}
