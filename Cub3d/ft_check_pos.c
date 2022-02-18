/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:03:35 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 13:15:36 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_pos_n_s(t_vars *vars, t_error_map *err, int a)
{
	vars->dir_x = -1 * a;
	vars->dir_y = 0.0;
	vars->plane_x = 0;
	vars->plane_y = 0.66 * a;
	err->pos++;
	return (1);
}

int	ft_pos_w_e(t_vars *vars, t_error_map *err, int a)
{
	vars->dir_x = 0;
	vars->dir_y = 1 * a;
	vars->plane_x = 0.66 * a;
	vars->plane_y = 0;
	err->pos++;
	return (1);
}

int	check_pos(t_vars *vars, t_error_map *err, char map)
{
	if (map == 'N')
		return (ft_pos_n_s(vars, err, 1));
	else if (map == 'W')
		return (ft_pos_w_e(vars, err, -1));
	else if (map == 'S')
		return (ft_pos_n_s(vars, err, -1));
	else if (map == 'E')
		return (ft_pos_w_e(vars, err, 1));
	else if (map == '0' || map == '1' || map == '2' || map == ' '
		|| map == '\t')
		return (0);
	ft_exit_error(vars, "ERROR: INCORRECT MAP!");
	return (0);
}

int	check_char_map(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != 'N' && c != 'W' && c != 'S'
		&& c != 'E')
		return (1);
	return (0);
}
