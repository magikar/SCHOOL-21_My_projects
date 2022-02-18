/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loading_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:30:22 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 13:18:27 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_load_image(t_vars *vars, int *texture, char *path, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(vars->mlx, path, &img->img_width,
			&img->img_height);
	if (!(img->img))
		ft_exit_error(vars, "ERROR: INCORRECT PART TEXTURE");
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x]
				= img->addr[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(vars->mlx, img->img);
}

void	ft_load_texture(t_vars *vars)
{
	t_data	img;

	ft_load_image(vars, vars->texture[0], vars->tex_name[0], &img);
	ft_load_image(vars, vars->texture[1], vars->tex_name[1], &img);
	ft_load_image(vars, vars->texture[2], vars->tex_name[2], &img);
	ft_load_image(vars, vars->texture[3], vars->tex_name[3], &img);
	ft_load_image(vars, vars->texture[4], vars->tex_name[4], &img);
	ft_load_image(vars, vars->texture[5], "pics/mossy.xpm", &img);
	ft_load_image(vars, vars->texture[6], "pics/bluestone.xpm", &img);
	ft_load_image(vars, vars->texture[7], "pics/colorstone.xpm", &img);
}
