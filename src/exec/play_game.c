/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 14:08:30 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub3d *cub)
{
	int	i = 0;
	
	while (i < 5)
	{
		free(cub->param->textures[i]);
		i++;
	}
	free(cub->param->textures);
	mlx_destroy_window(cub->ptr, cub->window);
	mlx_destroy_display(cub->ptr);
	free(cub->player);
	free(cub->ptr);
	free(cub->data);
	free(cub->param);
	free(cub->xpm);
	free(cub->minimap);
	free_vars(cub->vars);
	exit(0);
}

int	mouse_move_hook(int x, int y, t_cub3d *cub)
{
	int		old_x;
	double	speed;

	(void)y;
	mlx_mouse_get_pos(cub->ptr, cub->window, &x, &y);
	old_x = WIDTH / 2;
	speed = 0;
	if (x < old_x)
		speed = -3.5;
	else if (x > old_x)
		speed = 3.5;
	// if (speed)
	// 	cub->player->fov += speed;
	mlx_mouse_move(cub->ptr, cub->window, old_x, HEIGHT / 2);
	return (0);
}

void	play_game(t_cub3d cub, t_vars *vars)
{
	cub.player = ft_calloc(1, sizeof(t_player));
	if (!cub.player)
		ft_err("Malloc error", vars);
	init_game(vars, &cub);
	cub.data = init_data(vars);
	if (!cub.data)
		ft_err("Malloc error", vars);
	cub.param = ft_calloc(1, sizeof(t_textures));
	if (!cub.param)
		ft_err("Malloc error", vars);
	cub.xpm = ft_calloc(1, sizeof(t_xpm));
	if (!cub.xpm)
		ft_err("Malloc error", vars);
	cub.vars = vars;
	init_textures(&cub);
	init_direction(&cub);
	cub.minimap = ft_calloc(1, sizeof(t_minimap));
	if (!cub.minimap)
		ft_err("Malloc error", vars);
	// mlx_mouse_hide(cub.ptr, cub.window);
	main_loop(&cub);
}
