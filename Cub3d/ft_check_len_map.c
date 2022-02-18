/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:43:55 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 13:11:19 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_len_map(t_vars *vars, char **char_map)
{
	int	i;
	int	j;
	int	max_len;

	i = 0;
	max_len = 0;
	while (char_map[i])
	{
		j = ft_strlen(char_map[i]);
		if (max_len < j)
			max_len = j;
		i++;
	}
	vars->map_height = i;
	vars->map_width = max_len;
}

int	**ft_check_len_and_malloc_map(t_vars *vars, char **char_map)
{
	int	i;
	int	**map;

	i = 0;
	ft_len_map(vars, char_map);
	check_sprite_number(vars, char_map, 0, 0);
	check_valid_map(vars, char_map, vars->map_width, vars->map_height);
	map = (int **)malloc(sizeof(int *) * (vars->map_height + 1));
	if (!map)
		ft_exit_error(vars, "ERROR: FAIL MALLOC! WTF?!?!");
	while (i < vars->map_height)
	{
		map[i] = (int *)malloc(sizeof(int) * (vars->map_width));
		if (!map[i])
			ft_exit_error(vars, "ERROR: FAIL MALLOC! WTF?!?!");
		i++;
	}
	return (map);
}

void	ft_copy_char_in_int(int *map, int char_map)
{
	if (char_map >= '0' && char_map <= '9')
		*map = char_map - '0';
	else
		*map = 1;
}

void	ft_copy_map_int(t_vars *vars, t_error_map *err, char **char_map,
						int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (char_map[i][j])
		{
			if (check_pos(vars, err, char_map[i][j]))
			{
				vars->pos_x = (double)i + 0.5;
				vars->pos_y = (double)j + 0.5;
				map[i][j] = 0;
			}
			else
				ft_copy_char_in_int(&(map[i][j]), char_map[i][j]);
			j++;
		}
		while (j < vars->map_width)
			map[i][j++] = 1;
		i++;
	}
}
