/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:07:25 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/12 23:06:18 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_ext(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 4)
		return (1);
	i -= 4;
	if (ft_strncmp(path + i, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	file_size(char *argv, t_vars *vars)
{
	int		file;
	int		size;
	char	c;

	size = 0;
	file = open(argv, O_RDONLY);
	if (file < 0)
		ft_err("File open", vars);
	while (read(file, &c, 1) > 0)
		size++;
	if (read(file, &c, 1) < 0)
	{
		close(file);
		ft_err("Unreadable", vars);
	}
	close(file);
	return (size);
}

char	*str_file(char *path, t_vars *vars)
{
	int		size_of_file;
	int		file;
	char	*buff;

	if (map_ext(path))
		ft_err("Incorrect map link", vars);
	size_of_file = file_size(path, vars);
	if (size_of_file == -1)
		ft_err("Map size", vars);
	buff = malloc(sizeof(char) * (size_of_file + 1));
	if (!buff)
		return (NULL);
	file = open(path, O_RDONLY);
	if (read(file, buff, size_of_file) > 0)
	{
		buff[size_of_file] = '\0';
		return (close(file), buff);
	}
	else
	{
		close(file);
		free(buff);
		ft_err("Unreadable", vars);
	}
	return (NULL);
}
