/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:31:04 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:04:37 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_param_wall_1(t_vars *vars, t_new_img *val_img, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)vars->win_width - 1;
	val_img->ray_dir_x = vars->dir_x + vars->plane_x * camera_x;
	val_img->ray_dir_y = vars->dir_y + vars->plane_y * camera_x;
	val_img->map_x = (int)vars->pos_x;
	val_img->map_y = (int)vars->pos_y;
	val_img->delta_dist_x = fabs(1 / val_img->ray_dir_x);
	val_img->delta_dist_y = fabs(1 / val_img->ray_dir_y);
}

void	ft_param_wall_2(t_vars *vars, t_new_img *val_img)
{
	if (val_img->ray_dir_x < 0)
	{
		val_img->step_x = -1;
		val_img->side_dist_x = (vars->pos_x - val_img->map_x)
			* val_img->delta_dist_x;
	}
	else
	{
		val_img->step_x = 1;
		val_img->side_dist_x = (val_img->map_x + 1.0 - vars->pos_x)
			* val_img->delta_dist_x;
	}
	if (val_img->ray_dir_y < 0)
	{
		val_img->step_y = -1;
		val_img->side_dist_y = (vars->pos_y - val_img->map_y)
			* val_img->delta_dist_y;
	}
	else
	{
		val_img->step_y = 1;
		val_img->side_dist_y = (val_img->map_y + 1.0 - vars->pos_y)
			* val_img->delta_dist_y;
	}
}

void	ft_param_wall_3(t_vars *vars, t_new_img *val_img)
{
	val_img->hit = 0;
	while (val_img->hit == 0)
	{
		if (val_img->side_dist_x < val_img->side_dist_y)
		{
			val_img->side_dist_x += val_img->delta_dist_x;
			val_img->map_x += val_img->step_x;
			val_img->side = 0;
		}
		else
		{
			val_img->side_dist_y += val_img->delta_dist_y;
			val_img->map_y += val_img->step_y;
			val_img->side = 1;
		}
		if (vars->w_map[val_img->map_x][val_img->map_y] == 1)
			val_img->hit = 1;
	}
}

void	ft_param_wall_4(t_vars *vars, t_new_img *val_img)
{
	if (val_img->side == 0)
		val_img->perp_wall_dist = (val_img->map_x - vars->pos_x + (1
					- val_img->step_x) / 2) / val_img->ray_dir_x;
	else
		val_img->perp_wall_dist = (val_img->map_y - vars->pos_y + (1
					- val_img->step_y) / 2) / val_img->ray_dir_y;
	val_img->line_height = (int)(vars->win_height / val_img->perp_wall_dist);
	val_img->draw_start = -val_img->line_height / 2 + vars->win_height / 2;
	if (val_img->draw_start < 0)
		val_img->draw_start = 0;
	val_img->draw_end = val_img->line_height / 2 + vars->win_height / 2;
	if (val_img->draw_end >= vars->win_height)
		val_img->draw_end = vars->win_height - 1;
	if (val_img->side == 0)
		val_img->wall_x = vars->pos_y + val_img->perp_wall_dist
			* val_img->ray_dir_y;
	else
		val_img->wall_x = vars->pos_x + val_img->perp_wall_dist
			* val_img->ray_dir_x;
	val_img->wall_x -= floor(val_img->wall_x);
}

void	ft_param_wall_5(t_vars *vars, t_new_img *val_img, int x)
{
	val_img->tex_x = (int)(val_img->wall_x * 64.0);
	if ((val_img->side == 0 && val_img->ray_dir_x > 0)
		|| (val_img->side == 1 && val_img->ray_dir_y < 0))
		val_img->tex_x = 63 - val_img->tex_x;
	val_img->step = 1.0 * 64 / val_img->line_height;
	val_img->tex_pos = (val_img->draw_start - vars->win_height / 2
			+ val_img->line_height / 2) * val_img->step;
	val_img->tex_y = (int)val_img->tex_pos & 63;
	val_img->tex_pos += val_img->step;
	vars->z_buffer[x] = val_img->perp_wall_dist;
}
