/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:31:35 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:18:07 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_color_texture(t_vars *vars, t_new_img *val_img)
{
	int	color;

	color = 0;
	if (val_img->side == 1)
	{
		if (val_img->step_y > 0)
			color = vars->texture[0][64 * val_img->tex_y + val_img->tex_x];
		if (val_img->step_y < 0)
			color = vars->texture[1][64 * val_img->tex_y + val_img->tex_x];
	}
	if (val_img->side == 0)
	{
		if (val_img->step_x > 0)
			color = vars->texture[2][64 * val_img->tex_y + val_img->tex_x];
		if (val_img->step_x < 0)
			color = vars->texture[3][64 * val_img->tex_y + val_img->tex_x];
	}
	return (color);
}

void	ft_verline(t_vars *vars, t_new_img *val_img, int x)
{
	int	start;
	int	color;

	start = 0;
	while (start < val_img->draw_start)
		my_mlx_pixel_put(&(vars->img), x, start++, vars->ceilling);
	while (start < val_img->draw_end)
	{
		val_img->tex_pos += val_img->step;
		val_img->tex_y = (int)val_img->tex_pos & 63;
		color = ft_get_color_texture(vars, val_img);
		my_mlx_pixel_put(&(vars->img), x, start++, color);
	}
	while (start < vars->win_height)
		my_mlx_pixel_put(&(vars->img), x, start++, vars->floor);
}
