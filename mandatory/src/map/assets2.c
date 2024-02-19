/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:54:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/19 10:39:22 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	update_color_link(char ***old_link, char *new_link, t_vars *vars,
		char **lines_of_files)
{
	if (*old_link)
	{
		free(new_link);
		ft_free_map(lines_of_files);
		ft_err("Incorrect asset", vars);
	}
	*old_link = check_colors(new_link, vars, lines_of_files, new_link);
	free(new_link);
}

int	is_digit(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (count > 1)
			return (1);
		if ((s[i] < '0' || s[i] > '9') && s[i] != ',')
			return (1);
		if (s[i] == ',' && !s[i + 1])
			return (1);
		else if (s[i] == ',')
			count++;
		else
			count = 0;
		i++;
	}
	return (0);
}

char	**check_colors(char *s, t_vars *vars, char **lines_of_files,
		char *new_link)
{
	char	**str;
	int		i;

	if (is_digit(s))
		ft_err("Wrong colors", vars);
	str = ft_split(s, ',');
	i = 0;
	while (str[i])
		i++;
	if (i != 3 || ft_atoi(str[0]) < 0 || ft_atoi(str[0]) > 255
		|| ft_atoi(str[1]) < 0 || ft_atoi(str[1]) > 255 || ft_atoi(str[2]) < 0
		|| ft_atoi(str[2]) > 255)
	{
		free(new_link);
		ft_free_map(lines_of_files);
		ft_free_map(str);
		ft_err("Wrong colors", vars);
	}
	return (str);
}

void	base_assets2(t_vars *vars)
{
	if (!vars->assets->c_link)
	{
		vars->assets->c_link = malloc(sizeof(char *) * 4);
		if (!vars->assets->c_link)
			ft_err("Malloc assets err", vars);
		vars->assets->c_link[0] = ft_strdup("13");
		vars->assets->c_link[1] = ft_strdup("49");
		vars->assets->c_link[2] = ft_strdup("75");
		vars->assets->c_link[3] = NULL;
	}
}

void	base_assets(t_vars *vars)
{
	if (!vars->assets->no_link)
		vars->assets->no_link = ft_strdup("./assets/wood.xpm");
	if (!vars->assets->so_link)
		vars->assets->so_link = ft_strdup("./assets/wood.xpm");
	if (!vars->assets->we_link)
		vars->assets->we_link = ft_strdup("./assets/wood.xpm");
	if (!vars->assets->ea_link)
		vars->assets->ea_link = ft_strdup("./assets/wood.xpm");
	if (!vars->assets->f_link)
	{
		vars->assets->f_link = malloc(sizeof(char *) * 4);
		if (!vars->assets->f_link)
			ft_err("Malloc assets err", vars);
		vars->assets->f_link[0] = ft_strdup("82");
		vars->assets->f_link[1] = ft_strdup("84");
		vars->assets->f_link[2] = ft_strdup("88");
		vars->assets->f_link[3] = NULL;
	}
	base_assets2(vars);
}
