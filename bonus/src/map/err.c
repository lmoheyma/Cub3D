/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:11:58 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/19 08:58:15 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_err(char *err, t_vars *vars)
{
	free_vars(vars);
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(err, 1);
	exit(EXIT_FAILURE);
}

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	free_assets(vars);
	if (vars->game_data)
		free(vars->game_data);
	ft_free_map(vars->map);
	if (vars->map_str)
		free(vars->map_str);
	free(vars);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !(*map))
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_assets2(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->assets->f_link)
	{
		while (vars->assets->f_link[i])
			free(vars->assets->f_link[i++]);
		free(vars->assets->f_link);
	}
	i = 0;
	if (vars->assets->c_link)
	{
		while (vars->assets->c_link[i])
			free(vars->assets->c_link[i++]);
		free(vars->assets->c_link);
	}
}

void	free_assets(t_vars *vars)
{
	if (!vars->assets)
		return ;
	if (vars->assets->no_link)
		free(vars->assets->no_link);
	if (vars->assets->so_link)
		free(vars->assets->so_link);
	if (vars->assets->we_link)
		free(vars->assets->we_link);
	if (vars->assets->ea_link)
		free(vars->assets->ea_link);
	free_assets2(vars);
	free(vars->assets);
}
