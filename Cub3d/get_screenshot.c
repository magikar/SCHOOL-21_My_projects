/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:31:46 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 15:20:53 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_creat_head(t_vars *vars, unsigned char *head, int size)
{
	head[0] = (unsigned char) 'B';
	head[1] = (unsigned char) 'M';
	head[2] = (unsigned char)size;
	head[3] = (unsigned char)(size >> 8);
	head[4] = (unsigned char)(size >> 16);
	head[5] = (unsigned char)(size >> 24);
	head[10] = (unsigned char)54;
	head[14] = (unsigned char)40;
	head[18] = (unsigned char)vars->win_width;
	head[19] = (unsigned char)(vars->win_width >> 8);
	head[20] = (unsigned char)(vars->win_width >> 16);
	head[21] = (unsigned char)(vars->win_width >> 24);
	head[22] = (unsigned char)vars->win_height;
	head[23] = (unsigned char)(vars->win_height >> 8);
	head[24] = (unsigned char)(vars->win_height >> 16);
	head[25] = (unsigned char)(vars->win_height >> 24);
	head[26] = (unsigned char)1;
	head[28] = (unsigned char)24;
}

void	ft_creat_img(t_vars *vars, int fd)
{
	int		x;
	int		y;
	char	*color;

	y = vars->win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < vars->win_width)
		{
			color = (char *)vars->img.addr + (y * vars->img.line_length
					+ x * (vars->img.bits_per_pixel / 8));
			write(fd, color, 3);
			x++;
		}
		y--;
	}
}

int	get_screen(t_vars *vars)
{
	int				size;
	int				fd;
	int				i;
	unsigned char	head[54];

	i = 0;
	while (i < 54)
		head[i++] = (char)0;
	if (vars->win_width % 4)
		vars->win_width -= (vars->win_width % 4);
	size = vars->win_width * vars->win_height + 54;
	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd <= 0)
		ft_exit_error(vars, "ERROR: UNABLE TO CREAT FILE");
	ft_creat_head(vars, head, size);
	write(fd, head, 54);
	ft_creat_img(vars, fd);
	close(fd);
	exit(0);
}
