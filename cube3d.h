/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <roudouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:30:05 by akremcht          #+#    #+#             */
/*   Updated: 2022/06/08 10:46:01 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE_MINI_MAP 6
# define SCREENWIDTH 1280
# define SCREENHEIGHT 720

# define EAST 1
# define NORTH 3
# define WEST 0
# define SOUTH 2

typedef struct texture {
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct player {
	float		pos_x;
	float		pos_y;
	char		direction;
	float		move_speed;
	float		rot_speed;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
}	t_player;

typedef struct keys {
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}	t_keys;

typedef struct s_file
{
	int			f[3];
	int			c[3];
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**map;
	int			map_len;
	float		pos_x;
	float		pos_y;
	char		dir;
}	t_file;

typedef struct cub3d {
	t_player	*player;
	t_texture	*texture;
	t_keys		*keys;
	t_file		*file;
	void		*mlx;
	void		*mlx_win;
	int			floor_color;
	int			ceil_color;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		camera_x;
	float		ray_dir_x;
	float		ray_dir_y;
	int			map_x;
	int			map_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			hit;
	int			step_x;
	int			step_y;
	float		side_dist_x;
	float		side_dist_y;
	int			side;
	float		ray_length;
	int			tex_n;
	float		wall_x;
	int			tex_x;
	int			tex_y;
	float		step;
	float		tex_pos;
	int			start_end[2];
	char		**map;
	int			line_height;
}	t_cub3d;

// execution
int				render(t_cub3d *cub3d);
void			render_mini_map(t_cub3d *cube3d);
void			add_player_to_map2d(t_cub3d *cub3d);
void			draw_floar_and_ceil(t_cub3d *cube3d);
int				key_press(int keycode, t_cub3d *cub3d);
void			my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);
void			init_screen(t_cub3d *cub3d, char *title);
void			init(t_cub3d *cub3d, t_file *file);
void			draw_screen(t_cub3d *cub3d);

/* dda functions */
void			init_vars(t_cub3d *cub3d, int i);
void			init_dist(t_cub3d *cub3d);
void			wall_collision_for_ray(t_cub3d *cub3d);
void			check_key(t_cub3d *cube3d);
int				key_release(int keycode, t_cub3d *cube3d);
int				close_window(t_cub3d *cub3d);
void			load_all_texture(t_cub3d *cub, t_file *file);
void			free_and_exit(t_cub3d *cub3d, char *msg);
void			handle_player_movement(t_cub3d *cube3d);
void			handle_camera(t_cub3d *cube3d);
int				execution(t_file *file);
unsigned int	get_color(t_texture *t, int x, int y);
int				create_trgb(int r, int g, int b);
void			set_direction_of_player(t_cub3d *cub3d);
void			calc_dist(t_cub3d *cub3d);
void			which_texture(t_cub3d *cub3d, int x_or_y);
void			init_color(t_cub3d *cub3d, int texture_num);

// parsing
void			print_errors(int e);
t_file			*initialize_file(int fd, char *map_path);
int				parse_rgb_colors(t_file *file, char *str);
int				check_colors(t_file *file, int check);
int				parse_paths(t_file *file, char *str);
int				arr_len(char **arr);
void			arr_free(char **arr);
int				ft_isspace(char c);
int				count_c_in_str(char *str, char c);
int				rmf_spcs_i(char *str);
int				rml_spcs_i(char *str);
int				read_map(t_file *file, char *str, int is_read);
int				check_map(t_file *file);
void			free_file(t_file *file);

#endif