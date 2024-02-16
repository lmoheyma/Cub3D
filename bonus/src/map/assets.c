/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:54:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/15 21:48:38 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	base_assets(t_vars *vars)
{
	if (!vars->assets->no_link)
		vars->assets->no_link = ft_strdup("./assets/eagle.xpm");
	if (!vars->assets->so_link)
		vars->assets->so_link = ft_strdup("./assets/greystone.xpm");
	if (!vars->assets->we_link)
		vars->assets->we_link = ft_strdup("./assets/purplestone.xpm");
	if (!vars->assets->ea_link)
		vars->assets->ea_link = ft_strdup("./assets/red.xpm");
	if (!vars->assets->f_link)
	{
		vars->assets->f_link[0] = "200";
		vars->assets->f_link[1] = "200";
		vars->assets->f_link[2] = "200";
		vars->assets->f_link[3] = NULL;
	}
	if (!vars->assets->c_link)
	{
		vars->assets->c_link[0] = "200";
		vars->assets->c_link[1] = "200";
		vars->assets->c_link[2] = "200";
		vars->assets->c_link[3] = NULL;
	}
}

void	update_link(char **old_link, char *new_link, t_vars *vars,
		char **lines_of_files)
{
	if (*old_link)
	{
		free(new_link);
		ft_free_map(lines_of_files);
		ft_err("Incorrect asset", vars);
	}
	*old_link = new_link;
}

void	update_asset_link(char *s, char *asset_case, t_vars *vars,
		char **lines_of_files)
{
	if (ft_strncmp(s, "NO", 2) == 0)
		update_link(&vars->assets->no_link, asset_case, vars, lines_of_files);
	else if (ft_strncmp(s, "SO", 2) == 0)
		update_link(&vars->assets->so_link, asset_case, vars, lines_of_files);
	else if (ft_strncmp(s, "WE", 2) == 0)
		update_link(&vars->assets->we_link, asset_case, vars, lines_of_files);
	else if (ft_strncmp(s, "EA", 2) == 0)
		update_link(&vars->assets->ea_link, asset_case, vars, lines_of_files);
	else if (ft_strncmp(s, "F", 1) == 0)
		update_color_link(&vars->assets->f_link, asset_case, vars,
			lines_of_files);
	else if (ft_strncmp(s, "C", 1) == 0)
		update_color_link(&vars->assets->c_link, asset_case, vars,
			lines_of_files);
}

void	edit_asset(char *s, t_vars *vars, char **lines_of_files)
{
	char	*asset_case;

	asset_case = NULL;
	if (ft_strncmp(s, "NO", 2) == 0 || ft_strncmp(s, "SO", 2) == 0
		|| ft_strncmp(s, "WE", 2) == 0 || ft_strncmp(s, "EA", 2) == 0)
		asset_case = put_link_of_asset(asset_case, s + 2, vars, lines_of_files);
	else
		asset_case = put_link_of_asset(asset_case, s + 1, vars, lines_of_files);
	update_asset_link(s, asset_case, vars, lines_of_files);
}

char	*put_link_of_asset(char *asset_case, char *s, t_vars *vars,
		char **lines_of_files)
{
	int	i;

	i = 0;
	skip_spaces(s, &i);
	if (!s[i])
	{
		ft_free_map(lines_of_files);
		ft_err("Incorrect asset", vars);
	}
	asset_case = ft_strdup_space(s + i);
	while (s[i] && !is_spaces(s[i]))
		i++;
	skip_spaces(s, &i);
	if (s[i])
	{
		ft_free_map(lines_of_files);
		ft_err("Incorrect asset", vars);
	}
	return (asset_case);
}
