/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:46:37 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/12 10:07:07 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**map_clone(char **lines_of_files, t_vars *vars)
{
	char	**map;
	int		i;

	i = 0;
	while (lines_of_files[i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		ft_err("Map clone malloc", vars);
	i = 0;
	while (lines_of_files[i])
	{
		map[i] = ft_strdup(lines_of_files[i]);
		if (!map[i])
			ft_err("Map clone malloc", vars);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	get_map(char **lines_of_files, int i, t_vars *vars)
{
	if (check_char(lines_of_files + i))
	{
		ft_free_map(lines_of_files);
		ft_err("Wrong char", vars);
	}
	if (check_void(lines_of_files + i))
	{
		ft_free_map(lines_of_files);
		ft_err("Incorrect map", vars);
	}
	if (contour(lines_of_files + i))
	{
		ft_free_map(lines_of_files);
		ft_err("Map not close", vars);
	}
	vars->map = map_clone(lines_of_files + i, vars);
}

void	map_loop(char *map_str, t_vars *vars)
{
	char	**lines_of_files;
	int		i;

	i = -1;
	lines_of_files = ft_split(map_str, '\n');
	while (lines_of_files[++i])
	{
		if (ft_strncmp(lines_of_files[i], "NO", 2) == 0
			|| ft_strncmp(lines_of_files[i], "SO", 2) == 0
			|| ft_strncmp(lines_of_files[i], "WE", 2) == 0
			|| ft_strncmp(lines_of_files[i], "EA", 2) == 0
			|| ft_strncmp(lines_of_files[i], "F", 1) == 0
			|| ft_strncmp(lines_of_files[i], "C", 1) == 0)
			edit_asset(lines_of_files[i], vars, lines_of_files);
		else
		{
			get_map(lines_of_files, i, vars);
			break ;
		}
	}
	ft_free_map(lines_of_files);
}

void	launch_map(t_vars *vars, char **argv)
{
	vars->map_str = str_file(argv[1], vars);
	if (!vars->map_str)
		ft_err("Str malloc", vars);
	map_loop(vars->map_str, vars);
	base_assets(vars);
	if (!vars->map)
		ft_err("No map in the file", vars);
}
