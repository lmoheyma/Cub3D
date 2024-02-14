/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:54:33 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/14 14:15:02 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// void	init_assets(t_vars *vars, void *ptr)
// {
// 	int	width;
// 	int	height;

// 	vars->assets->no_asset = mlx_xpm_file_to_image(ptr,
// 			vars->assets->no_link, &width, &height);
// 	if (!vars->assets->no_asset)
// 		ft_err("Render assets", vars);
// 	vars->assets->so_asset = mlx_xpm_file_to_image(ptr,
// 			vars->assets->so_link, &width, &height);
// 	if (!vars->assets->so_asset)
// 		ft_err("Render assets", vars);
// 	vars->assets->we_asset = mlx_xpm_file_to_image(ptr,
// 			vars->assets->we_link, &width, &height);
// 	if (!vars->assets->we_asset)
// 		ft_err("Render assets", vars);
// 	vars->assets->ea_asset = mlx_xpm_file_to_image(ptr,
// 			vars->assets->ea_link, &width, &height);
// 	if (!vars->assets->ea_asset)
// 		ft_err("Render assets", vars);
// }

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