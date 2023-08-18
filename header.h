/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoindre <fcoindre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:39:29 by fcoindre          #+#    #+#             */
/*   Updated: 2023/08/17 16:39:33 by fcoindre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>

# include "includes/get_next_line/get_next_line.h"
# include "includes/libft/libft.h"
# include "includes/mlx/mlx.h"

# define WIDTH 1440
# define HEIGHT 960

# define FOV 60
# define SIZE_WALL 64
# define SCALE_MINI_MAP 8

# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_R 15
# define KEY_M 46
# define KEY_ESC 53
# define KEY_ARR_R 124
# define KEY_ARR_L 123

# define SKY_COLOR 0x2211FF
# define FLOOR_COLOR 0x556B2F

# define R_SPEED 0.06
# define SPEED 5

typedef struct s_utils
{
	void	*mlx;
	void	*win;
}	t_utils;

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlib
{
	t_data	data;
	t_utils	utils;
}	t_mlib;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_tab_of_vec
{
	t_coord	v1;
	t_coord	v2;
	t_vec	v3;
}	t_tab;

typedef struct s_player
{
	t_coord	coord_ini;
	t_coord	pos;
	t_coord	pos2d;
	t_vec	dir;
	float	speed;
}	t_player;

typedef struct s_map
{
	char	**matrix;
	int		height_matrix;
	int		width_matrix;
	int		height_map;
	int		width_map;
}	t_map;

typedef struct s_scene
{
	int			mini_map;
	int			sky_color;
	int			floor_color;
	t_map		map;
	t_player	player;
}	t_scene;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	q;
	int	r;
	int	arrow_r;
	int	arrow_l;
}	t_keys;

typedef struct s_sprite
{
	char	*path;
	t_data	data_spr;
	int		sprite_w;
	int		sprite_h;
}	t_sprite;

typedef struct s_sprites
{
	t_sprite	*wall_north;
	t_sprite	*wall_south;
	t_sprite	*wall_east;
	t_sprite	*wall_west;
}	t_sprites;

typedef struct s_general
{
	t_scene		*scene;
	t_mlib		*mlib;
	t_keys		*keys;
	t_sprites	*sprites;
}	t_general;

/* main.c */
void		free_general(t_general *general);

/* main_utils.c */
t_general	*create_general(char **walls);
int			feed_scene(t_general *g, char **copy, t_coord floor, t_coord ceil);
void		chk_file(int argc, char *argv[]);
void		get_ceil_floo(char **copy, char **walls, char **ceil_floo);
t_coord		set_color_vec(char **copy, char **w, char **clrs, char *clr);

/* parsing/args_manager.c */
char		*get_filename(const char *file_path);
char		*get_extension(char *filename);
int			filename_is_valid(const char *file_path);
int			file_exists(char *filename);
int			arg_manager(char *file_path);

/* parsing/copy_file_utils.c */
int			hit_a_wall(t_general *general, int x, int y);
int			get_size_file(char *filename);
char		**copy_file(char *filename);

/* parsing/parsing.c */
int			is_space(char c);
int			string_is_only_space(char *str);
char		*go_to_next_and_get_arg(char *line);
int			is_numeric(char *str);
t_coord		set_vector(char *str);
int			check_coord_color(t_coord color);
char		*get_floor_ceil(char **copy_of_file, char caract);
int			parser(char **copy);

/* parsing.c/initializer.c */
t_mlib		*init_mlib(t_general *general);
t_keys		*init_key(t_general *general);
t_sprite	*init_sprite(char *path);
t_sprites	*init_sprites(char **walls, t_general *general);

/* parsing/map_parser.c */
t_coord		get_player_coord(char **matrix);
char		get_letter_oreintation(char **matrix);
t_vec		get_player_orient(char **matrix);
int			parse_first_wall(char *line, char **matrix, char **map_uncompelted);
int			find_map(char **copy_file, int end_part_1);
int			get_height_map(char **copy_file, int ind_map);
int			get_width_map(char **map);
int			check_eof(char **copy_file, int ind_map, int h_map);
char		**map_creator(char **copy_file, int h_map, int ind_map);
int			check_caract_line(char *line);
int			check_caract_map(char **map_unc);
char		*line_matrix_creator(char *line, int w_matrix);
char		**matrix_creator(char **map_unc, int h_matrix, int w_matrix);
int			check_first_one(char *line);
int			check_last_one(char *line);
int			check_last_first_one(char **matrix, char **map_uncompleted);
int			check_right(char **matrix, int lin, int col, t_coord size_matrix);
int			check_top(char **matrix, int lin, int col, t_coord size_matrix);
int			check_bottom(char **matrix, int lin, int col, t_coord size_matrix);
int			check_left(char **matrix, int lin, int col, t_coord size_matrix);
int			onews(char c);
int			wall_inspector(char **m_u, char **matrix, t_coord size_matrix);
int			check_player(char **matrix, char **map_uncompleted);
t_coord		get_player_position(t_coord coord_ini, int size_wall);
int			init_map(t_map *map, char **copy, int end_parse_1);
int			map_parser(char **copy, int end_parse_1);

/* srcs/render2D/minimap.c */
void		draw_grid(t_general *general);
void		draw_wall(t_general *general, t_coord coord_wall);
void		render_wall2d(t_general *general);
void		draw_player(t_general *general);
void		draw_arrow(t_general *general, t_coord start_arrow, t_vec dir);
int			render_mini_map(t_general *general);

/* parsing/wall_manager.c */
char		*get_wall(char **copy_of_file, char first, char second);
char		**walls_manager(char **copy_of_file);
int			walls_manager_exists(char **walls);
char		*norm_get_no(char **walls, char **copy_of_file);
char		*norm_get_so(char **walls, char **copy_of_file);
char		*norm_get_ea(char **walls, char **copy_of_file);
char		*norm_get_we(char **walls, char **copy_of_file);

/* srcs/game_tools/utils.c */
int			hit_a_wall(t_general *general, int x, int y);
int			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			load_texture_png(t_general *general);
int			create_trgb(int t, int r, int g, int b);
t_coord		create_trgb_reverse(unsigned int color);
int			size_tab(char **tab);
void		ft_free_tabs(char **tab);
int			convert_coord_for_2D_X(int x);
int			convert_coord_for_2D_Y(int y);
t_coord		convertcoord2d(t_coord pos);
int			move(t_general *general);
void		init_window(t_general *general);

/* display.c */
void		print_tab(char **tab);
void		print_map(t_map map);
void		print_vec(t_vec vector);
void		print_coord(t_coord coord);
void		print_player(t_player player);
void		print_sprite(t_sprite *sprite);
void		print_sprites(t_sprites *sprites);
void		print_scene(t_scene *scene);

/* hook.c */
int			key_pression(int keycode, t_general *general);
int			key_release(int keycode, t_general *general);

/* keys_moves.c */
void		a_key(t_general *general, t_coord *c_p, t_coord *n_p, t_vec *dir);
void		s_key(t_general *general, t_coord *c_p, t_coord *n_p, t_vec *dir);
void		d_key(t_general *general, t_coord *c_p, t_coord *n_p, t_vec *dir);
void		w_key(t_general *general, t_coord *c_p, t_coord *n_p, t_vec *dir);
int			render_game(t_general *general);

#endif
