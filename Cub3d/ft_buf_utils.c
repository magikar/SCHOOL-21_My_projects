/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:23:26 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 17:32:38 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_win_resol(t_vars *vars, int *win, char *buf, int i)
{
	int	k;
	int	q;

	q = 0;
	i = skip_space(&(buf[0]), i);
	k = i;
	while (ft_isdigit(buf[k]))
		k++;
	if (buf[k] == '-' || (k - i) == 0)
		ft_exit_error(vars, "ERROR: INCORRECT RESOLUTION");
	if ((k - i) > 4)
	{
		i = skip_space_and_digit(&(buf[0]), i);
		return (i);
	}
	q = ft_atoi(&(buf[i]));
	if (q < 50)
		*win = 50;
	else
		*win = q;
	i = skip_space_and_digit(&(buf[0]), i);
	return (i);
}

int	ft_scr_resol(t_vars *vars, t_error_map *err, char *buf, int i)
{
	i += 2;
	i = ft_win_resol(vars, &(vars->win_width), &(buf[0]), i);
	i = ft_win_resol(vars, &(vars->win_height), &(buf[0]), i);
	i = skip_space(&(buf[0]), i);
	if (buf[i] != '\n')
		ft_exit_error(vars, "ERROR: INCORRECT MAP!");
	err->r++;
	return (i);
}

int	ft_record_text(t_vars *vars, int *err, char *buf, int text)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = skip_space(buf, i);
	while (buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
		vars->tex_name[text][j++] = buf[i++];
	vars->tex_name[text][j] = '\0';
	i = skip_space(buf, i);
	(*err)++;
	return (i);
}

int	ft_record_texture(t_vars *vars, t_error_map *err, char *buf)
{
	int	i;

	i = 0;
	if (!ft_memcmp(buf, "NO ", 3))
		i = ft_record_text(vars, &(err->no), (buf + 3), 0) + 3;
	else if (!ft_memcmp(buf, "SO ", 3))
		i = ft_record_text(vars, &(err->so), (buf + 3), 1) + 3;
	else if (!ft_memcmp(buf, "WE ", 3))
		i = ft_record_text(vars, &(err->we), (buf + 3), 2) + 3;
	else if (!ft_memcmp(buf, "EA ", 3))
		i = ft_record_text(vars, &(err->ea), (buf + 3), 3) + 3;
	else if (!ft_memcmp(buf, "S ", 2))
		i = ft_record_text(vars, &(err->s), (buf + 2), 4) + 2;
	return (i);
}

int	ft_check_comma(t_vars *vars, char buf)
{
	if (buf != ',')
		ft_exit_error(vars, "ERROR: INCORRECT SPLIT COLOR");
	return (1);
}
