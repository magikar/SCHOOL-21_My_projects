/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mall_spr_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:31:57 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 16:38:19 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_err(t_vars *vars, t_error_map *err)
{
	if (err->r != 1 || err->no != 2 || err->so != 2 || err->we != 2
		|| err->ea != 2 || err->s != 2 || err->f != 2 || err->c != 2
		|| err->pos != 1)
		ft_exit_error(vars, "ERROR: INCORRECT MAP!");
}

static void	sps_norma_za_kostil(t_vars *vars)
{
	if (vars->num_sprit > 0)
	{
		vars->sprites = (double **)malloc(sizeof(double *)
				* (vars->num_sprit + 1));
		if (!vars->sprites)
			ft_exit_error(vars, "ERROR: INCORRECT MAP!");
	}
}

int	check_sprite_number(t_vars *vars, char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				vars->num_sprit++;
			j++;
		}
		i++;
	}
	i = 0;
	sps_norma_za_kostil(vars);
	while (i < vars->num_sprit)
	{
		vars->sprites[i] = (double *)malloc(sizeof(double) * 2);
		if (!vars->sprites[i])
			ft_exit_error(vars, "ERROR: INCORRECT MAP!");
		i++;
	}
	return (1);
}

int	skip_space(char *buf, int i)
{
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	return (i);
}

int	skip_space_and_digit(char *buf, int i)
{
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	while (ft_isdigit(buf[i]))
		i++;
	return (i);
}
