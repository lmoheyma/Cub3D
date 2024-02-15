/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:54:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/15 15:07:49 by aleite-b         ###   ########.fr       */
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
	*old_link = check_colors(new_link, vars);
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

char	**check_colors(char *s, t_vars *vars)
{
	char	**str;
	int		i;

	if (is_digit(s))
		ft_err("Wrong colors", vars);
	str = ft_split(s, ',');
	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		ft_err("Wrong colors", vars);
	if (ft_atoi(str[0]) < 0
		|| ft_atoi(str[0]) > 255
		|| ft_atoi(str[1]) < 0
		|| ft_atoi(str[1]) > 255
		|| ft_atoi(str[2]) < 0
		|| ft_atoi(str[2]) > 255)
		ft_err("Wrong colors", vars);
	return (str);
}
