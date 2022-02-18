/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:52:29 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:45:26 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_render_next_frame(t_vars *vars)
{
	t_data	img_buff;

	ft_run(vars);
	img_buff.img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	img_buff.addr = (int *)mlx_get_data_addr(img_buff.img,
			&(img_buff.bits_per_pixel), &(img_buff.line_length),
			&(img_buff.endian));
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img = img_buff;
	ft_new_img(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	**read_map(char *file_cub, t_vars *vars)
{
	int			i;
	char		*buf;
	int			**map;
	char		**char_map;
	t_error_map	err;

	i = 0;
	null_err(&err);
	buf = ft_read_file_in_buf(vars, file_cub);
	ft_valid_buf(vars, &err, buf, &char_map);
	map = ft_check_len_and_malloc_map(vars, char_map);
	ft_copy_map_int(vars, &err, char_map, map);
	check_err(vars, &err);
	while (char_map[i])
	{
		free(char_map[i]);
		i++;
	}
	free(char_map);
	free(buf);
	return (map);
}

static void	sps_norma_za_kostil(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, vars->win_width, vars->win_height,
			"psevdo Wolfenshtein");
	vars->img.img = mlx_new_image(vars->mlx, vars->win_width, vars->win_height);
	vars->img.addr = (int *)mlx_get_data_addr(vars->img.img,
			&vars->img.bits_per_pixel, &vars->img.line_length,
			&vars->img.endian);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (argc == 1)
		ft_exit_error(&vars, "ERROR: NO MAP!");
	ft_vars_null(&vars);
	mlx_get_screen_size(&vars.win_width, &vars.win_height);
	vars.w_map = read_map(argv[1], &vars);
	ft_load_texture(&vars);
	vars.z_buffer = malloc(sizeof(float *) * vars.win_width);
	if (!vars.z_buffer)
		ft_exit_error(&vars, "ERROR: FAIL MALLOC! WTF?!?!");
	sps_norma_za_kostil(&vars);
	ft_new_img(&vars);
	if (argc == 3 && !ft_memcmp(argv[2], "--save", 7))
		get_screen(&vars);
	mlx_hook(vars.win, 2, 1L << 0, &ft_key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, &ft_key_release, &vars);
	mlx_hook(vars.win, 17, 1L << 0, &ft_esc, &vars);
	mlx_loop_hook(vars.mlx, &ft_render_next_frame, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
