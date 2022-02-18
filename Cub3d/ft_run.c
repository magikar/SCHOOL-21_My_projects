/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:31:16 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:16:14 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_run(t_vars *vars)
{
	double	alfa;

	alfa = 2 * PI / 180;
	if (vars->key.key_w)
		ft_run_w(vars, 1, 1);
	if (vars->key.key_s)
		ft_run_w(vars, -1, 1);
	if (vars->key.key_left)
		ft_rotat(vars, 1, alfa);
	if (vars->key.key_right)
		ft_rotat(vars, -1, alfa);
	if (vars->key.key_a)
		ft_run_a(vars, 1, 1);
	if (vars->key.key_d)
		ft_run_a(vars, -1, 1);
	return (0);
}

void	ft_run_w(t_vars *vars, int zn, int step)
{
	if (!vars->w_map[(int)(vars->pos_x + 3 * step * zn * vars->dir_x / SPEED)]
					[(int)vars->pos_y])
		vars->pos_x += step * zn * vars->dir_x / SPEED;
	if (!vars->w_map[(int)vars->pos_x]
		[(int)(vars->pos_y + 3 * step * zn * vars->dir_y / SPEED)])
		vars->pos_y += step * zn * vars->dir_y / SPEED;
}

void	ft_run_a(t_vars *vars, int zn, int step)
{
	if (!vars->w_map[(int)(vars->pos_x - 3 * step * zn * vars->dir_y / SPEED)]
					[(int)vars->pos_y])
		vars->pos_x -= step * zn * vars->dir_y / SPEED;
	if (!vars->w_map[(int)vars->pos_x][(int)(vars->pos_y
		+ 3 * step * zn * vars->dir_x / SPEED)])
		vars->pos_y += step * zn * vars->dir_x / SPEED;
}

void	ft_rotat(t_vars *vars, int zn, double alfa)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->dir_x;
	old_plane_x = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(zn * alfa) - vars->dir_y * sin(zn * alfa);
	vars->dir_y = old_dir_x * sin(zn * alfa) + vars->dir_y * cos(zn * alfa);
	vars->plane_x = vars->plane_x * cos(zn * alfa)
		- vars->plane_y * sin(zn * alfa);
	vars->plane_y = old_plane_x * sin(zn * alfa)
		+ vars->plane_y * cos(zn * alfa);
}
