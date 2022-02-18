/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:07:34 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:35:32 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_valid_pos_map_1(int i, int j, int x, int y)
{
	if (i == y - 1 || j == x)
		return (0);
	return (1);
}

int	ft_check_valid_pos_map_2(char **map, int i, int j)
{
	if (i == 0 || j == 0 || check_char_map(map[i][j - 1]) == 1 ||
	check_char_map(map[i][j + 1]) == 1 || check_char_map(map[i + 1][j]) == 1 ||
	check_char_map(map[i - 1][j]) == 1 || j >= (int)ft_strlen(map[i - 1])
	|| j >= (int)ft_strlen(map[i + 1]))
		return (0);
	return (1);
}

void	ft_check_valid_pos_map_3(t_vars *vars, int *n_s, int i, int j)
{
	vars->sprites[*n_s][0] = i + 0.5;
	vars->sprites[*n_s][1] = j + 0.5;
	(*n_s)++;
}

int	check_valid_map(t_vars *vars, char **map, int x, int y)
{
	int	i;
	int	j;
	int	num_sprite;

	i = 0;
	num_sprite = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '2' || map[i][j] == 'W' ||
			map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E')
			{
				if (!ft_check_valid_pos_map_1(i, j, x, y)
					|| !ft_check_valid_pos_map_2(map, i, j))
					ft_exit_error(vars, "ERROR: INCORRECT MAP!");
				if (map[i][j] == '2')
					ft_check_valid_pos_map_3(vars, &num_sprite, i, j);
			}
			j++;
		}
		i++;
	}
	return (1);
}
