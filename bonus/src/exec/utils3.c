/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:58:49 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/17 18:59:51 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_images(t_cub3d *cub)
{
	cub->xpm_void = NULL;
	cub->xpm_wall = NULL;
	cub->xpm_mndoor = NULL;
	cub->xpm_player = NULL;
}
