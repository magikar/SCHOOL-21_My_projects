/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_and_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:17:51 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 16:41:20 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_error(t_vars *vars, char *str)
{
	int	i;

	i = 0;
	if (vars->sprites)
	{
		while (i < vars->num_sprit)
			free(vars->sprites[i++]);
		free(vars->sprites);
	}
	i = 0;
	if (vars->w_map)
	{
		while (i < vars->map_height)
			free(vars->w_map[i++]);
		free(vars->w_map);
	}
	if (vars->z_buffer)
		free(vars->z_buffer);
	printf("<<%s>>\n", str);
	exit(-1);
}

int	ft_esc(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->num_sprit)
		free(vars->sprites[i++]);
	free(vars->sprites);
	i = 0;
	while (i < vars->map_height)
		free(vars->w_map[i++]);
	free(vars->w_map);
	free(vars->z_buffer);
	mlx_destroy_window(vars->mlx, vars->win);
	write(1, "<<GAME OVER>>\n", 14);
	exit(0);
}

void	ft_check_valid_file(t_vars *vars, char *file_cub)
{
	int	i;

	i = 0;
	while (file_cub[i])
		i++;
	if (ft_memcmp(&(file_cub[i - 4]), ".cub", 5))
		ft_exit_error(vars, "ERROR: INCORRECT NAME FILE");
}

static void	sps_norma_za_kostil(t_vars *vars, char **buf, char *str)
{
	char	*tmp;

	tmp = *buf;
	*buf = ft_strjoin(*buf, str);
	if (!(*buf))
		ft_exit_error(vars, "ERROR: FAIL MALLOC! WTF?!");
	free(tmp);
}

char	*ft_read_file_in_buf(t_vars *vars, char *file_cub)
{
	int		fd;
	int		bytes;
	char	str[201];
	char	*buf;

	ft_check_valid_file(vars, file_cub);
	buf = (char *)malloc(1);
	if (!buf)
		ft_exit_error(vars, "ERROR: FAIL MALLOC! WTF?!");
	buf[0] = '\0';
	fd = open(file_cub, O_RDONLY);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, str, 200);
		if (bytes < 0)
			ft_exit_error(vars, "ERROR: INCORRECT PART");
		else if (!bytes)
			break ;
		str[bytes] = '\0';
		sps_norma_za_kostil(vars, &buf, str);
	}
	close(fd);
	return (buf);
}
