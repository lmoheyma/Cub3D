/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:16:31 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/11 02:34:18 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	empty_mid_s2(char **lines_of_files, int j, int i)
{
	int	tmpj;

	tmpj = j;
	while (lines_of_files[tmpj + 1] && is_spaces(lines_of_files[tmpj][i]))
		tmpj++;
	if (!is_spaces(lines_of_files[tmpj][i]) && lines_of_files[tmpj][i] != '1')
		return (1);
	tmpj = j;
	while (tmpj > 0 && is_spaces(lines_of_files[tmpj][i]))
		tmpj--;
	if (!is_spaces(lines_of_files[tmpj][i]) && lines_of_files[tmpj][i] != '1')
		return (1);
	return (0);
}

int	empty_mid_s(char **lines_of_files, int j, int i)
{
	int	tmpi;

	tmpi = i;
	while (lines_of_files[j][tmpi] && is_spaces(lines_of_files[j][tmpi]))
		tmpi++;
	if (lines_of_files[j][tmpi] && lines_of_files[j][tmpi] != '1')
		return (1);
	tmpi = i;
	while (tmpi > 0 && is_spaces(lines_of_files[j][tmpi]))
		tmpi--;
	if (lines_of_files[j][tmpi] != '1')
		return (1);
	if (empty_mid_s2(lines_of_files, j, i))
		return (1);
	return (0);
}

int	empty_mid_z2(char **lines_of_files, int j, int i)
{
	int	tmpj;

	tmpj = j;
	while (lines_of_files[tmpj + 1] && ft_strchr("0NSEW",
			lines_of_files[tmpj][i]))
		tmpj++;
	if (!ft_strchr("0NSEW", lines_of_files[tmpj][i])
		&& lines_of_files[tmpj][i] != '1')
		return (1);
	tmpj = j;
	while (tmpj > 0 && ft_strchr("0NSEW", lines_of_files[tmpj][i]))
		tmpj--;
	if (!ft_strchr("0NSEW", lines_of_files[tmpj][i])
		&& lines_of_files[tmpj][i] != '1')
		return (1);
	return (0);
}

int	empty_mid_z(char **lines_of_files, int j, int i)
{
	int	tmpi;

	tmpi = i;
	while (lines_of_files[j][tmpi] && ft_strchr("0NSEW",
			lines_of_files[j][tmpi]))
		tmpi++;
	if (lines_of_files[j][tmpi] && lines_of_files[j][tmpi] != '1')
		return (1);
	tmpi = i;
	while (tmpi > 0 && ft_strchr("0NSEW", lines_of_files[j][tmpi]))
		tmpi--;
	if (lines_of_files[j][tmpi] != '1')
		return (1);
	if (empty_mid_z2(lines_of_files, j, i))
		return (1);
	return (0);
}

int	mid_of_map(char **lines_of_files, int j)
{
	int	i;

	i = 0;
	skip_spaces(lines_of_files[j], &i);
	if (lines_of_files[j][i] != '1')
		return (1);
	while (lines_of_files[j][i])
	{
		if (is_spaces(lines_of_files[j][i]))
		{
			if (empty_mid_s(lines_of_files, j, i))
				return (1);
		}
		else if (ft_strchr("0NSEW", lines_of_files[j][i]))
			if (empty_mid_z(lines_of_files, j, i))
				return (1);
		i++;
	}
	i--;
	while (is_spaces(lines_of_files[j][i]))
		i--;
	if (lines_of_files[j][i] != '1')
		return (1);
	return (0);
}
