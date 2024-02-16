/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/16 19:19:06 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	key_press(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		close_window(cub);
	else if (keycode == KEY_SPACE)
		door_check(cub);
	else if (keycode == KEY_LEFT_ARROW)
		cub->player->rotate -= 1;
	else if (keycode == KEY_RIGHT_ARROW)
		cub->player->rotate += 1;
	else if (keycode == KEY_W)
		cub->player->move_y = 1;
	else if (keycode == KEY_A)
		cub->player->move_x = -1;
	else if (keycode == KEY_S)
		cub->player->move_y = -1;
	else if (keycode == KEY_D)
		cub->player->move_x = 1;
	return (0);
}

int	key_release(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		close_window(cub);
	else if (keycode == KEY_W && cub->player->move_y == 1)
		cub->player->move_y = 0;
	else if (keycode == KEY_A && cub->player->move_x == -1)
		cub->player->move_x += 1;
	else if (keycode == KEY_S && cub->player->move_y == -1)
		cub->player->move_y = 0;
	else if (keycode == KEY_D == 1 && cub->player->move_x == 1)
		cub->player->move_x -= 1;
	else if (keycode == KEY_LEFT_ARROW && cub->player->rotate <= 1)
		cub->player->rotate = 0;
	else if (keycode == KEY_RIGHT_ARROW && cub->player->rotate >= -1)
		cub->player->rotate = 0;
	return (0);
}

void	listen_input(t_cub3d *cub)
{
	mlx_hook(cub->window, ClientMessage, NoEventMask, close_window, cub);
	mlx_hook(cub->window, KeyPress, KeyPressMask, key_press, cub);
	mlx_hook(cub->window, KeyRelease, KeyReleaseMask, key_release, cub);
	mlx_hook(cub->window, MotionNotify, PointerMotionMask, mouse_move_hook,
		cub);
}

int	display(t_cub3d *cub)
{
	int	i;

	cub->player->has_move += move_player(cub);
	// if (cub->player->has_move == 0)
	// 	return (0);
	init_textures_p(cub);
	raycasting(cub);
	display_sprite(cub, 0);
	int y = -1;
	while (++y < 10000)
		display_sprite(cub, 5);
	display_sprite(cub, 6);
	create_frame(cub);
	show_minimap(cub);
	usleep(100);
	// printf("x = %f   y = %f\n", cub->player->p_x, cub->player->p_y);
	i = 0;
	while (i < HEIGHT)
	{
		free(cub->param->textures_p[i]);
		i++;
	}
	free(cub->param->textures_p);
	return (0);
}

void	main_loop(t_cub3d *cub)
{
	int	i;

	init_textures_p(cub);
	raycasting(cub);
	display_sprite(cub, 0);
	display_sprite(cub, 5);
	display_sprite(cub, 6);
	create_frame(cub);
	setup_images(cub);
	show_minimap(cub);
	mlx_mouse_move(cub->ptr, cub->window, WIDTH / 2, HEIGHT / 2);
	listen_input(cub);
	i = 0;
	while (i < HEIGHT)
	{
		free(cub->param->textures_p[i]);
		i++;
	}
	free(cub->param->textures_p);
	mlx_loop_hook(cub->ptr, &display, cub);
	mlx_loop(cub->ptr);
}
