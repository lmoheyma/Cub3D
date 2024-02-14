/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:16:31 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/12 10:07:19 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	top_of_map(char **lines_of_files, int end)
{
	int		i;
	char	last_char;
	int		j;

	i = -1;
	last_char = '/';
	while (lines_of_files[0][++i])
	{
		if (lines_of_files[0][i] == '1')
			last_char = '1';
		else if (is_spaces(lines_of_files[0][i]))
		{
			if (last_char != '/')
			{
				j = 0;
				while (j <= end && is_spaces(lines_of_files[j][i]))
					j++;
				if (lines_of_files[j][i] != '1')
					return (1);
			}
		}
		else
			return (1);
	}
	return (0);
}

int	bot_of_map(char **lines_of_files, int end)
{
	int		i;
	char	last_char;
	int		j;

	i = -1;
	last_char = '/';
	while (lines_of_files[end][++i])
	{
		if (lines_of_files[end][i] == '1')
			last_char = '1';
		else if (is_spaces(lines_of_files[end][i]))
		{
			if (last_char != '/')
			{
				j = end;
				while (j >= 0 && is_spaces(lines_of_files[j][i]))
					j--;
				if (lines_of_files[j][i] != '1')
					return (1);
			}
		}
		else
			return (1);
	}
	return (0);
}

int	contour(char **lines_of_files)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (lines_of_files[i + 1])
		i++;
	if (top_of_map(lines_of_files, i))
		return (1);
	if (bot_of_map(lines_of_files, i))
		return (1);
	while (j < i)
	{
		if (mid_of_map(lines_of_files, j))
			return (1);
		j++;
	}
	return (0);
}

int	check_char(char **lines_of_files)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (lines_of_files[i])
	{
		j = 0;
		while (lines_of_files[i][j])
		{
			if (!(ft_strchr("01NSEW", lines_of_files[i][j])
				|| lines_of_files[i][j] == 32 || (lines_of_files[i][j] >= 9
						&& lines_of_files[i][j] <= 13)))
				return (1);
			if (ft_strchr("NSEW", lines_of_files[i][j]))
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_void(char **lines_of_files)
{
	int	end;
	int	i;

	end = 0;
	i = 0;
	while (lines_of_files[end + 1])
		end++;
	while (lines_of_files[i])
	{
		if (empty_line(lines_of_files[i]) && i != end)
			return (1);
		i++;
	}
	return (0);
}
