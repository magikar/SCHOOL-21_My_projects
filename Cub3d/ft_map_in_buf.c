/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_in_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:32:08 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:43:18 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_record_color(int *color, char *buf, int i, int bit)
{
	int	tmp_color;

	i = skip_space(buf, i);
	if (!ft_isdigit(buf[i]))
		return (0);
	tmp_color = ft_atoi(&(buf[i]));
	if (tmp_color < 0 || tmp_color > 255)
		return (0);
	*color = *color | (tmp_color << bit);
	i = skip_space_and_digit(&(buf[0]), i);
	return (i);
}

static void	ft_gg_norma(t_vars *vars, char *buf, int *i)
{
	*i = ft_record_color(&(vars->ceilling), &(buf[0]), *i + 2, 16);
	if (*i == 0)
		ft_exit_error(vars, "ERROR: INCORRECT COLOR FLOOR OR CEILLING");
	ft_check_comma(vars, buf[(*i)++]);
	*i = ft_record_color(&(vars->ceilling), &(buf[0]), *i, 8);
	if (*i == 0)
		ft_exit_error(vars, "ERROR: INCORRECT COLOR FLOOR OR CEILLING");
	ft_check_comma(vars, buf[(*i)++]);
	*i = ft_record_color(&(vars->ceilling), &(buf[0]), *i, 0);
	if (*i == 0)
		ft_exit_error(vars, "ERROR: INCORRECT COLOR FLOOR OR CEILLING");
}

int	ft_record_fl_cei(t_vars *vars, t_error_map *err, char *buf, int i)
{
	if (!ft_memcmp(&(buf[i]), "F ", 2))
	{
		i = ft_record_color(&(vars->floor), &(buf[0]), i + 2, 16);
		if (i == 0)
			ft_exit_error(vars, "ERROR: INCORRECT COLOR FLOOR OR CEILLING");
		ft_check_comma(vars, buf[i++]);
		i = ft_record_color(&(vars->floor), &(buf[0]), i, 8);
		if (i == 0)
			ft_exit_error(vars, "ERROR: INCORRECT COLOR FLOOR OR CEILLING");
		ft_check_comma(vars, buf[i++]);
		i = ft_record_color(&(vars->floor), &(buf[0]), i, 0);
		if (i == 0)
			ft_exit_error(vars, "ERROR: INCORRECT COLOR FLOOR OR CEILLING");
		err->f++;
	}
	else if (!ft_memcmp(&(buf[i]), "C ", 2))
	{
		ft_gg_norma(vars, buf, &i);
		err->c++;
	}
	return (i);
}

void	ft_split_buf(t_vars *vars, char ***char_map, char *buf, int *i)
{
	while (buf[*i] != '\n')
		(*i)--;
	*char_map = ft_split(&buf[*i], '\n');
	if (!(*char_map))
		ft_exit_error(vars, "ERROR: FAIL MALLOC! WTF?!?!");
	while (buf[*i])
	{
		if (!ft_memcmp(&buf[*i], "\n\n", 2))
			ft_exit_error(vars, "ERROR: BAD SPLIT MAP");
		(*i)++;
	}
	*i = -69;
}

void	ft_valid_buf(t_vars *vars, t_error_map *err, char *buf,
			char ***char_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[i])
	{
		i = skip_space(buf, i);
		if (!ft_memcmp(&(buf[i]), "R ", 2))
			i = ft_scr_resol(vars, err, buf, i);
		else if (ft_record_texture(vars, err, &(buf[i])))
			i += ft_record_texture(vars, err, &(buf[i]));
		else if (ft_record_fl_cei(vars, err, &(buf[i]), 0))
			i += ft_record_fl_cei(vars, err, &(buf[i]), 0);
		else if (ft_isdigit(buf[i]))
		{
			ft_split_buf(vars, char_map, &(buf[0]), &i);
			break ;
		}
		else if (buf[i] != '\n')
			ft_exit_error(vars, "ERROR: INCORRECT FILE CONTENT!");
		i++;
	}
	if (i != -69)
		ft_exit_error(vars, "ERROR: INCORRECT MAP!");
}
