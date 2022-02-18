/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:30:53 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:02:33 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_param_spr_2(t_vars *vars, t_sprites *val_sprites, int order)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = vars->sprites[order][0] - vars->pos_x;
	sprite_y = vars->sprites[order][1] - vars->pos_y;
	inv_det = 1.0 / (vars->dir_y * vars->plane_x
			- vars->dir_x * vars->plane_y);
	val_sprites->transform_x = inv_det
		* (vars->dir_y * sprite_x - vars->dir_x * sprite_y);
	val_sprites->transform_y = inv_det
		* (vars->plane_x * sprite_y - vars->plane_y * sprite_x);
	val_sprites->sprite_screen_x = (int)((vars->win_width / 2)
			* (1 + val_sprites->transform_x / val_sprites->transform_y));
	val_sprites->sprite_height = (int)fabs(vars->win_height
			/ val_sprites->transform_y);
	val_sprites->draw_start_y = -val_sprites->sprite_height / 2
		+ vars->win_height / 2;
	if (val_sprites->draw_start_y < 0)
		val_sprites->draw_start_y = 0;
	val_sprites->draw_end_y = val_sprites->sprite_height / 2
		+ vars->win_height / 2;
	if (val_sprites->draw_end_y >= vars->win_height)
		val_sprites->draw_end_y = vars->win_height - 1;
}

void	ft_param_spr_4(t_vars *vars, t_sprites *val_sprites, int x)
{
	int	y;
	int	d;
	int	color;

	y = val_sprites->draw_start_y;
	if (val_sprites->transform_y > 0 && val_sprites->transform_y
		< vars->z_buffer[x])
	{
		while (y < val_sprites->draw_end_y)
		{
			d = y * 256 - vars->win_height * 128
				+ val_sprites->sprite_height * 128;
			val_sprites->tex_y = ((d * 64) / val_sprites->sprite_height) / 256;
			color = vars->texture[4][64 * val_sprites->tex_y
				+ val_sprites->tex_x];
			if (color)
				my_mlx_pixel_put(&vars->img, x, y, color);
			y++;
		}
	}
}

void	ft_param_spr_3(t_vars *vars, t_sprites *val_sprites)
{
	int	x;
	int	draw_start_x;

	val_sprites->sprite_width = (int)fabs(vars->win_height
			/ val_sprites->transform_y);
	draw_start_x = -val_sprites->sprite_width / 2
		+ val_sprites->sprite_screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	val_sprites->draw_end_x = val_sprites->sprite_width / 2
		+ val_sprites->sprite_screen_x;
	if (val_sprites->draw_end_x >= vars->win_width)
		val_sprites->draw_end_x = vars->win_width - 1;
	x = draw_start_x;
	while (x < val_sprites->draw_end_x)
	{
		val_sprites->tex_x = (int)((256 * (x - (-val_sprites->sprite_width / 2
							+ val_sprites->sprite_screen_x)) * 64
					/ val_sprites->sprite_width) / 256);
		ft_param_spr_4(vars, val_sprites, x);
		x++;
	}
}

void	ft_param_spr_1(t_vars *vars, int *spr_order)
{
	int	i;

	i = 0;
	while (i < vars->num_sprit)
	{
		ft_param_spr_2(vars, &(vars->val_sprites), spr_order[i]);
		ft_param_spr_3(vars, &(vars->val_sprites));
		i++;
	}
}
