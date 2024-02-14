/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:53:22 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 15:48:13 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	put_pixel(t_tmpimg *img, int x, int y, int color)
{
	int	pixel;

	pixel = y * (img->sl / 4) + x;
	img->addr[pixel] = color;
}
