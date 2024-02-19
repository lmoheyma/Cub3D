/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:46:45 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/02/19 12:41:01 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	close_window2(t_cub3d *cub)
{
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
}

int	close_window(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		if (cub->param->textures[i])
			free(cub->param->textures[i]);
		i++;
	}
	i = 0;
	while (i < cub->param->nb_sprite)
	{
		if (cub->sprite[i])
			free(cub->sprite[i]);
		i++;
	}
	close_window2(cub);
	exit(0);
}

int	mouse_move_hook(int x, int y, t_cub3d *cub)
{
	static int	old_x = WIDTH / 2;

	(void)y;
	if (x == old_x)
	{
		return (0);
	}
	else if (x < old_x)
		cub->player->has_move += rotate_mouse_player(cub, -1);
	else if (x > old_x)
		cub->player->has_move += rotate_mouse_player(cub, 1);
	mlx_mouse_move(cub->ptr, cub->window, WIDTH / 2, HEIGHT / 2);
	return (0);
}

void	play_game(t_cub3d cub, t_vars *vars)
{
	cub.player = ft_calloc(1, sizeof(t_player));
	if (!cub.player)
		ft_err("Malloc error", vars);
	init_game(vars, &cub);
	cub.data = init_data(vars);
	cub.param = ft_calloc(1, sizeof(t_textures));
	cub.s_param = ft_calloc(1, sizeof(t_sprite_param));
	cub.minimap = ft_calloc(1, sizeof(t_minimap));
	if (!cub.minimap || !cub.s_param || !cub.param || !cub.data)
		ft_err("Malloc error", vars);
	cub.vars = vars;
	cub.size = 64;
	init_animation(&cub);
	cub.param->nb_sprite = 23;
	cub.sprite = (t_sprite **)ft_calloc(cub.param->nb_sprite + 1,
			sizeof(t_sprite *));
	if (!cub.sprite)
		ft_err("Malloc error", vars);
	init_sprite(&cub);
	init_images(&cub);
	init_textures(&cub);
	init_direction(&cub);
	mlx_mouse_hide(cub.ptr, cub.window);
	main_loop(&cub);
}
