/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:30:33 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 16:40:11 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc(t_vars *vars, t_new_img *val_img)
{
	int	x;

	x = 0;
	while (x < vars->win_width)
	{
		ft_param_wall_1(vars, val_img, x);
		ft_param_wall_2(vars, val_img);
		ft_param_wall_3(vars, val_img);
		ft_param_wall_4(vars, val_img);
		ft_param_wall_5(vars, val_img, x);
		ft_verline(vars, val_img, x);
		x++;
	}
}

static void	ft_kostil_sps_norma(t_vars *vars, int *spr_order,
double *spr_distance)
{
	if (vars->num_sprit > 1)
		ft_sort_sprites(vars, spr_order, spr_distance, vars->num_sprit);
	if (vars->num_sprit > 0)
		ft_param_spr_1(vars, spr_order);
	if (vars->num_sprit)
	{
		free(spr_distance);
		free(spr_order);
	}
}

void	ft_new_img(t_vars *vars)
{
	int		i;
	int		*spr_order;
	double	*spr_distance;

	i = 0;
	if (vars->num_sprit)
	{
		spr_order = (int *)malloc(sizeof(int) * vars->num_sprit);
		spr_distance = (double *)malloc(sizeof(double) * vars->num_sprit);
		if (!spr_order || !spr_distance)
			ft_exit_error(vars, "ERROR: FAIL MALLOC! WTF?!?!");
	}
	ft_calc(vars, &(vars->val_img));
	while (i < vars->num_sprit)
	{
		spr_order[i] = i;
		spr_distance[i] = pow((vars->pos_x - vars->sprites[i][0]), 2)
			+ pow((vars->pos_y - vars->sprites[i][1]), 2);
		i++;
	}
	ft_kostil_sps_norma(vars, spr_order, spr_distance);
}
