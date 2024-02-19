/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:58:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 10:20:45 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_images(t_cub3d *cub)
{
	cub->xpm_void = NULL;
	cub->xpm_wall = NULL;
	cub->xpm_mndoor = NULL;
	cub->xpm_player = NULL;
}

void	add_torchs_textures(t_cub3d *cub)
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
