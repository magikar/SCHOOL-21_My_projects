/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:32:35 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 16:05:20 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"

# define PI		3.14159265358979323846264338327950288419716939937510
# define SPEED	20.0

typedef struct s_key {
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_cntrl;
}					t_key;

typedef struct s_error_map {
	int				r;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				s;
	int				f;
	int				c;
	int				pos;
}					t_error_map;

typedef struct s_data {
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_data;

typedef struct s_new_img
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				hide;
	int				hit;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			step;
	double			tex_pos;
	double			wall_x;
}					t_new_img;

typedef struct s_sprites
{
	int				sprite_screen_x;
	int				sprite_width;
	int				sprite_height;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	double			inv_det;
	double			sprite_x;
	double			sprite_y;
	double			transform_x;
	double			transform_y;
}					t_sprites;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	int				**w_map;
	int				**buf;
	int				texture[8][64*64];
	int				win_width;
	int				win_height;
	int				map_width;
	int				map_height;
	int				floor;
	int				ceilling;
	int				num_sprit;
	char			tex_name[5][100];
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			**sprites;
	float			*z_buffer;
	t_data			img;
	t_key			key;
	t_new_img		val_img;
	t_sprites		val_sprites;
}					t_vars;

typedef struct s_pair
{
	double			dist;
	int				order;
}					t_pair;

typedef struct s_map_size
{
	int				map_hight;
	int				map_width;
}					t_map_size;

void				ft_sort_order(t_pair *orders, int amount);
void				ft_sort_sprites(t_vars *vars, int *order, double *dist,
						int amount);
void				ft_load_image(t_vars *vars, int *texture, char *path,
						t_data *img);
void				ft_load_texture(t_vars *vars);
int					ft_render_next_frame(t_vars *vars);
int					ft_run(t_vars *vars);
void				ft_run_w(t_vars *vars, int zn, int step);
void				ft_run_a(t_vars *vars, int zn, int step);
void				ft_rotat(t_vars *vars, int zn, double alfa);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				ft_vars_null(t_vars *vars);
void				ft_key_null(t_key *key);
int					ft_key_press(int keycode, t_vars *vars);
int					ft_key_release(int keycode, t_vars *vars);
int					ft_esc(t_vars *vars);
void				ft_read_map(t_vars *vars);
int					skip_space(char *buf, int i);
int					skip_space_and_digit(char *buf, int i);
int					**read_map(char *file_cub, t_vars *vars);
int					ft_isdigit(int c);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *nptr);
char				*ft_strjoin(char const *s1, char const *s2);
int					check_sprite_number(t_vars *vars, char **map, int i, int j);
int					check_valid_map(t_vars *vars, char **map, int x, int y);
void				ft_exit_error(t_vars *vars, char *str);
int					get_screen(t_vars *vars);
void				ft_check_valid_file(t_vars *vars, char *file_cub);
char				*ft_read_file_in_buf(t_vars *vars, char *file_cub);
void				ft_valid_buf(t_vars *vars, t_error_map *err, char *buf,
						char ***char_map);
void				ft_split_buf(t_vars *vars, char ***char_map, char *buf,
						int *i);
int					ft_record_fl_cei(t_vars *vars, t_error_map *err,
						char *buf, int i);
int					ft_record_color(int *color, char *buf, int i,
						int bit);
int					ft_record_texture(t_vars *vars, t_error_map *err,
						char *buf);
int					ft_record_text(t_vars *vars, int *err, char *buf,
						int text);
int					ft_scr_resol(t_vars *vars, t_error_map *err, char *buf,
						int i);
int					ft_win_resol(t_vars *vars, int *win, char *buf, int i);
int					**ft_check_len_and_malloc_map(t_vars *vars,
						char **char_map);
void				ft_copy_map_int(t_vars *vars, t_error_map *err,
						char **char_map, int **map);
int					check_pos(t_vars *vars, t_error_map *err, char map);
void				null_err(t_error_map *err);
void				check_err(t_vars *vars, t_error_map *err);
int					check_char_map(char c);
int					ft_check_comma(t_vars *vars, char buf);
void				ft_param_wall_1(t_vars *vars, t_new_img *val_img, int x);
void				ft_param_wall_2(t_vars *vars, t_new_img *val_img);
void				ft_param_wall_3(t_vars *vars, t_new_img *val_img);
void				ft_param_wall_4(t_vars *vars, t_new_img *val_img);
void				ft_param_wall_5(t_vars *vars, t_new_img *val_img, int x);
void				ft_calc(t_vars *vars, t_new_img *val_img);
void				ft_param_spr_1(t_vars *vars, int *spr_order);
void				ft_param_spr_2(t_vars *vars, t_sprites *val_sprites,
						int order);
void				ft_param_spr_3(t_vars *vars, t_sprites *val_sprites);
void				ft_param_spr_4(t_vars *vars, t_sprites *val_sprites, int x);
void				ft_new_img(t_vars *vars);
int					ft_get_color_texture(t_vars *vars, t_new_img *val_img);
void				ft_verline(t_vars *vars, t_new_img *val_img, int x);

#endif
