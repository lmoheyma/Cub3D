/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_and_height.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:11:58 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/12 10:47:31 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_size_of_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	get_width(char **map)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		if (max_len < get_size_of_line(map[i]))
			max_len = get_size_of_line(map[i]);
		i++;
	}
	return (max_len);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
