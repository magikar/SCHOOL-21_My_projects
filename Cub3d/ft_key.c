/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:30:08 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 13:16:03 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_vars_null(t_vars *vars)
{
	vars->floor = 0;
	vars->ceilling = 0;
	vars->num_sprit = 0;
	ft_key_null(&(vars->key));
}

void	ft_key_null(t_key *key)
{
	key->key_w = 0;
	key->key_s = 0;
	key->key_a = 0;
	key->key_d = 0;
	key->key_left = 0;
	key->key_right = 0;
	key->key_cntrl = 0;
}

int	ft_key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_esc(vars);
	else if (keycode == 256)
		vars->key.key_cntrl = 1;
	else if (keycode == 126 || keycode == 13)
		vars->key.key_w = 1;
	else if (keycode == 125 || keycode == 1)
		vars->key.key_s = 1;
	else if (keycode == 0)
		vars->key.key_a = 1;
	else if (keycode == 2)
		vars->key.key_d = 1;
	else if (keycode == 123)
		vars->key.key_left = 1;
	else if (keycode == 124)
		vars->key.key_right = 1;
	return (0);
}

int	ft_key_release(int keycode, t_vars *vars)
{
	if (keycode == 126 || keycode == 13)
		vars->key.key_w = 0;
	else if (keycode == 256)
		vars->key.key_cntrl = 0;
	else if (keycode == 125 || keycode == 1)
		vars->key.key_s = 0;
	else if (keycode == 0)
		vars->key.key_a = 0;
	else if (keycode == 2)
		vars->key.key_d = 0;
	else if (keycode == 123)
		vars->key.key_left = 0;
	else if (keycode == 124)
		vars->key.key_right = 0;
	return (0);
}

void	null_err(t_error_map *err)
{
	err->r = 0;
	err->no = 0;
	err->so = 0;
	err->we = 0;
	err->ea = 0;
	err->s = 0;
	err->f = 0;
	err->c = 0;
	err->pos = 0;
}
