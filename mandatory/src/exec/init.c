/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:52:24 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 07:25:39 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_map(char **worldMap)
{
	int	i;
	int	j;

	i = 0;
	while (worldMap[i])
	{
		j = -1;
		while (worldMap[i][++j])
			printf("%c ", worldMap[i][j]);
		printf("\n");
		i++;
	}
}

t_data	*init_data(t_vars *vars)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		ft_err("Malloc error", vars);
	data->map = vars->map;
	data->map_height = get_height(data->map);
	data->map_width = get_width(data->map);
	return (data);
}

// void	init_player(t_cub3d cub, t_vars *vars)
// {
// 	cub.player->p_x = vars->game_data->xpos_p + 0.5;
// 	cub.player->p_y = vars->game_data->ypos_p + 0.5;
// }
