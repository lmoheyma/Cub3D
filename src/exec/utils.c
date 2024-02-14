/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:14:01 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/14 15:22:19 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

double	distance(double p_y, double p_x, double w_x, double w_y)
{
	return (sqrt(((p_x - w_x) * (p_x - w_x)) + ((p_y - w_y) * (p_y - w_y))));
}

void	set_image(t_cub3d *cub, t_tmpimg *img, int x, int y)
{
	if (cub->param->textures_p[y][x] > 0)
		put_pixel(img, x, y, cub->param->textures_p[y][x]);
	else if (y < HEIGHT / 2)
		put_pixel(img, x, y, cub->param->c_color);
	else if (y < HEIGHT - 1)
		put_pixel(img, x, y, cub->param->f_color);
}

void init_image(t_cub3d *cub, t_tmpimg *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->sl = 0;
	img->endian = 0;
	img->img = mlx_new_image(cub->ptr, WIDTH, HEIGHT);
	if (!img->img)
	{
		// free
		exit(1);
	}
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->endian);
}

void create_frame(t_cub3d *cub)
{
	t_tmpimg img;
	int	x;
	int	y;

	y = 0;
	img.img = NULL;
	init_image(cub, &img);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			set_image(cub, &img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->ptr, cub->window, img.img, 0, 0);
	mlx_destroy_image(cub->ptr, img.img);
}

int	key_press(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		close_window(cub);
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
	// else if (keycode == KEY_SPACE)
	// 	door_check(cub, cub->player->fov);
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

void listen_input(t_cub3d *cub)
{
	mlx_hook(cub->window, ClientMessage, NoEventMask, close_window, cub);
	mlx_hook(cub->window, KeyPress, KeyPressMask, key_press, cub);
	mlx_hook(cub->window, KeyRelease, KeyReleaseMask, key_release, cub);
	mlx_hook(cub->window, MotionNotify, PointerMotionMask, mouse_move_hook, cub);
}

int display(t_cub3d *cub)
{
	cub->player->has_move += move_player(cub);
	if (cub->player->has_move == 0)
		return (0);
	init_textures_p(cub);
	raycasting(cub);
	create_frame(cub);
	// show_minimap(cub);
	int	i = 0;
	
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
	init_textures_p(cub);
	raycasting(cub);
	create_frame(cub);
	// setup_images(cub);
	// show_minimap(cub);
	listen_input(cub);
	int	i = 0;
	
	while (i < HEIGHT)
	{
		free(cub->param->textures_p[i]);
		i++;
	}
	free(cub->param->textures_p);
	mlx_loop_hook(cub->ptr, &display, cub);
	mlx_loop(cub->ptr);
}
