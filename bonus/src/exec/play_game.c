/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/15 15:04:23 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub3d *cub)
{
	int	i;

	i = 0;
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
	// free(cub->minimap);
	free_vars(cub->vars);
	exit(0);
}

int	mouse_move_hook(int x, int y, t_cub3d *cub)
{
	int		old_x;
	double	speed;

	old_x = WIDTH / 2;
	mlx_mouse_get_pos(cub->ptr, cub->window, &x, &y);
	if (x == old_x)
		return (0);
	if (abs(x - old_x) < 20)
		return (0);
	speed = 0;
	if (x < old_x)
		speed = -0.2;
	else if (x > old_x)
		speed = 0.2;
	if (speed < 0)
		rotate_right(cub, speed);
	if (speed > 0)
		rotate_left(cub, speed);
	cub->player->has_move += 1;
	mlx_mouse_move(cub->ptr, cub->window, WIDTH / 2, HEIGHT / 2);
	display(cub);
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
	cub.vars = vars;
	init_textures(&cub);
	init_direction(&cub);
	cub.minimap = ft_calloc(1, sizeof(t_minimap));
	if (!cub.minimap)
		ft_err("Malloc error", vars);
	main_loop(&cub);
}
