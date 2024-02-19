/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:36:22 by aleite-b          #+#    #+#             */
/*   Updated: 2024/02/19 08:57:18 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080
# define PI 3.14159265358979323846
# define SQUARE 64
# define HALF_SQUARE 32
# define MINIMAP_SPEED 4
# define MAP_SQUARE 10
# define RED 0xFF0000
# define ROTATE_SPEED 12.0
# define MOVE_SPEED 30.0

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_SPACE 0x0020
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364

typedef struct s_fc
{
	int				p;
	int				cell_x;
	int				cell_y;
	int				t_x;
	int				t_y;
	float			raydir_x0;
	float			raydir_y0;
	float			raydir_x1;
	float			raydir_y1;
	float			pos_z;
	float			row_distance;
	float			floor_step_x;
	float			floor_step_y;
	float			floor_x;
	float			floor_y;
}					t_fc;

typedef struct s_assets
{
	char			*no_link;
	char			*so_link;
	char			*we_link;
	char			*ea_link;
	char			**f_link;
	char			**c_link;
}					t_assets;

typedef struct s_game
{
	int				xpos_p;
	int				ypos_p;
}					t_game;

typedef struct s_vars
{
	t_assets		*assets;
	char			**map;
	char			*map_str;
	t_game			*game_data;
	void			*mlx;
	void			*window;
}					t_vars;

typedef struct s_data
{
	char			**map;
	int				p_x;
	int				p_y;
	int				map_width;
	int				map_height;
}					t_data;

typedef struct s_player
{
	double			p_x;
	double			p_y;
	double			angle;
	char			dir;
	int				move_x;
	int				move_y;
	int				has_move;
	int				rotate;
}					t_player;

typedef struct s_textures
{
	int				x;
	int				y;
	int				index;
	double			step;
	double			pos;
	int				color;
	int				f_color;
	int				c_color;
	int				nb_sprite;
	int				**textures;
	int				**textures_p;
}					t_textures;

typedef struct s_minimap
{
	int				player_x;
	int				player_y;
}					t_minimap;

typedef struct s_tmpimg
{
	void			*img;
	int				*addr;
	int				bpp;
	int				sl;
	int				endian;
}					t_tmpimg;

typedef struct s_sprite
{
	double			x;
	double			y;
	int				texture;
	int				collected;
}					t_sprite;

typedef struct s_sprite_param
{
	double			*z_buffer;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				texture_x;
	int				texture_y;
}					t_sprite_param;

typedef struct s_cub3d
{
	void			*ptr;
	void			*window;
	void			*image;
	void			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				side;
	int				step_x;
	int				step_y;
	int				line_height;
	double			wall_x;
	int				draw_start;
	int				draw_end;
	int				directions;
	void			*xpm_void;
	void			*xpm_wall;
	void			*xpm_mndoor;
	void			*xpm_player;
	int				size;
	int				collected_keys;
	int				frame_rate;
	int				animation_speed;
	int				frame_count;
	int				current_frame;
	t_data			*data;
	t_player		*player;
	t_vars			*vars;
	t_textures		*param;
	t_minimap		*minimap;
	t_tmpimg		*tmp;
	t_sprite		**sprite;
	t_sprite_param	*s_param;
	t_fc			*f_c;
}					t_cub3d;

// Sprites
t_sprite			*add_sprite(t_cub3d *cub, double x, double y, int texture);
void				init_sprite(t_cub3d *cub);
void				display_sprite(t_cub3d *cub, int index);
void				show_sprite(t_cub3d *cub);
void				init_animation(t_cub3d *cub);
void				update_animation(t_cub3d *cub);
void				update_frame(t_cub3d *cub);
void				add_torchs1(t_cub3d *cub, double x, double y, int start,
						int end);
void				display_barrel(t_cub3d *cub);

// Minimap
void				fshow_minimap(t_cub3d *cub);
void				fsetup_images(t_cub3d *cub);
void				show_minimap(t_cub3d *cub);
void				print_map(char **worldMap);
void				show_minimap_wall(t_cub3d *cub, char **map);
void				setup_images(t_cub3d *cub);

// Raycasting
int					raycasting(t_cub3d *cub);
void				init_raycast(t_cub3d *cub, int x);
void				dda(t_cub3d *cub);
void				dda2(t_cub3d *cub);
void				line_height(t_cub3d *cub);
void				init_direction(t_cub3d *cub);

// Floor & Ceiling
void				floor_ceiling(t_cub3d *cub);

// Door
void				door_check(t_cub3d *cub);

// Color utils
void				put_pixel(t_tmpimg *img, int x, int y, int color);
int					rgb(int r, int g, int b);

// Texture
void				init_textures(t_cub3d *cub);
void				init_textures_p(t_cub3d *cub);
void				set_directions(t_cub3d *cub);
void				update_textures(t_cub3d *cub, int x);

// Rotate camera
int					rotate_right(t_cub3d *cub, double speed);
int					rotate_left(t_cub3d *cub, double speed);
int					rotate_player(t_cub3d *cub, int rotate);
void				mouse_rotate(t_cub3d *cub, double speed);
int					rotate_mouse_player(t_cub3d *cub, int rotate);

// Movements WASD
int					move_back(t_cub3d *cub);
int					move_up(t_cub3d *cub);
int					move_left(t_cub3d *cub);
int					move_right(t_cub3d *cub);
int					move_player(t_cub3d *cub);

// Directions
char				directions(t_cub3d *cub, double w_x, double w_y);

// Utils
double				distance(double p_y, double p_x, double w_x, double w_y);
double				fisheye(t_cub3d *cub, int angle);
void				hook_function(t_cub3d cub);
int					mouse_move_hook(int x, int y, t_cub3d *cub);
int					key_hook(int keycode, t_cub3d *cub);
int					close_window(t_cub3d *cub);
void				create_frame(t_cub3d *cub);
int					display(t_cub3d *cub);
void				img_error(t_cub3d *cub);

// Init
t_data				*init_data(t_vars *vars);
void				init_player(t_cub3d cub, t_vars *vars);
void				main_loop(t_cub3d *cub);
void				init_images(t_cub3d *cub);

// XPM
void				path_to_xpm(t_cub3d *cub);
void				init_path(t_cub3d *cub);

// MAPING
// ASSETS

void				base_assets(t_vars *vars);
void				update_link(char **old_link, char *new_link, t_vars *vars,
						char **lines_of_files);
void				update_asset_link(char *s, char *asset_case, t_vars *vars,
						char **lines_of_files);
void				edit_asset(char *s, t_vars *vars, char **lines_of_files);
char				*put_link_of_asset(char *asset_case, char *s, t_vars *vars,
						char **lines_of_files);
void				init_assets(t_vars *vars, void *ptr);
void				update_color_link(char ***old_link, char *new_link,
						t_vars *vars, char **lines_of_files);
char				**check_colors(char *s, t_vars *vars,
						char **lines_of_files, char *new_link);

// FILE

int					map_ext(char *path);
int					file_size(char *argv, t_vars *vars);
char				*str_file(char *path, t_vars *vars);

// MAP

void				get_map(char **lines_of_files, int i, t_vars *vars);
void				map_loop(char *map_str, t_vars *vars);
void				launch_map(t_vars *vars, char **argv);

int					top_of_map(char **lines_of_files, int end);
int					bot_of_map(char **lines_of_files, int end);
int					contour(char **lines_of_files);
int					check_char(char **lines_of_files);
int					check_void(char **lines_of_files);

int					empty_mid_s(char **lines_of_files, int j, int i);
int					empty_mid_s2(char **lines_of_files, int j, int i);
int					empty_mid_z(char **lines_of_files, int j, int i);
int					empty_mid_z2(char **lines_of_files, int j, int i);
int					mid_of_map(char **lines_of_filesint, int j);

int					get_size_of_line(char *s);
int					get_width(char **map);
int					get_height(char **map);

// ERR

void				ft_err(char *err, t_vars *vars);
void				free_vars(t_vars *vars);
void				ft_free_map(char **map);
void				free_assets(t_vars *vars);

// UTILS

int					is_spaces(char c);
void				skip_spaces(char *str, int *i);
int					empty_line(char *s);
void				skip_empty_lines(char **str, int *i);
char				*ft_strdup_space(char *s);
int					ft_strcmp(const char *s1, const char *s2);

// GAME

void				init_game(t_vars *vars, t_cub3d *cub);
void				init_vars(t_vars *vars);

// PLAY GAME

void				play_game(t_cub3d cub, t_vars *vars);

#endif