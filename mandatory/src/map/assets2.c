/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:54:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/14 15:45:59 by aleite-b         ###   ########.fr       */
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
	*old_link = ft_split(new_link, ',');
	free(new_link);
}
