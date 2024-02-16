/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/16 15:02:45 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < 6)
		free(cub->param->textures[i++]);
	i = 0;
	while (i < cub->param->nb_sprite)
		free(cub->sprite[i++]);
	free(cub->param->textures);
	free(cub->sprite);
	free(cub->s_param->z_buffer);
	free(cub->s_param);
	mlx_destroy_window(cub->ptr, cub->window);
	if (cub->xpm_void)
		mlx_destroy_image(cub->ptr, cub->xpm_void);
	if (cub->xpm_wall)
		mlx_destroy_image(cub->ptr, cub->xpm_wall);
	if (cub->xpm_player)
		mlx_destroy_image(cub->ptr, cub->xpm_player);
	if (cub->xpm_mndoor)
		mlx_destroy_image(cub->ptr, cub->xpm_mndoor);
	mlx_destroy_display(cub->ptr);
	free(cub->player);
	free(cub->ptr);
	free(cub->data);
	free(cub->param);
	free(cub->minimap);
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
		speed = -0.1;
	else if (x > old_x)
		speed = 0.1;
	if (speed < 0)
		rotate_right(cub, speed);
	if (speed > 0)
		rotate_left(cub, speed);
	cub->player->has_move += 1;
	mlx_mouse_move(cub->ptr, cub->window, WIDTH / 2, HEIGHT / 2);
	// display(cub);
	return (0);
}

// int	mouse_move_hook(int x, int y, t_cub3d *cub)
// {
// 	static int		old_x = WIDTH / 2;
// 	(void)y;
	
// 	if (x > WIDTH - 20)
// 	{
// 		x = 20;
// 		mlx_mouse_move(cub->ptr, cub->window, x, y);
// 	}
// 	if (x < 20)
// 	{
// 		x = WIDTH - 20;
// 		mlx_mouse_move(cub->ptr, cub->window, x, y);
// 	}
// 	if (x == old_x)
// 		return (0);
// 	else if (x < old_x)
// 		cub->player->has_move += rotate_player(cub, -1);
// 	else if (x > old_x)
// 		cub->player->has_move += rotate_player(cub, 1);
// 	old_x = x;
// 	// mlx_mouse_move(cub->ptr, cub->window, WIDTH / 2, HEIGHT / 2);
// 	return (0);
// }

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
	cub.size = 64;
	init_textures(&cub);
	cub.s_param = ft_calloc(1, sizeof(t_sprite_param));
	if (!cub.s_param)
		ft_err("Malloc error", vars);
	cub.f_c = ft_calloc(1, sizeof(t_fc));
	if (!cub.f_c)
		ft_err("Malloc error", vars);
	init_sprite(&cub);
	init_direction(&cub);
	cub.minimap = ft_calloc(1, sizeof(t_minimap));
	if (!cub.minimap)
		ft_err("Malloc error", vars);
	mlx_mouse_hide(cub.ptr, cub.window);
	main_loop(&cub);
}
